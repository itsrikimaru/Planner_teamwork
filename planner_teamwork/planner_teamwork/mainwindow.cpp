#include "mainwindow.h"

#include<QMessageBox>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDateTimeEdit>
#include<QTableView>
#include<QHeaderView>
#include<QDebug>
#include<QDialog>
#include<QLabel>
#include<QTextEdit>
#include<QSqlRecord>

//引入QCharts相关的文件，实现qtchars可视化所需要
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE


#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置饼状图
    createpieSewies();
    //设置QCharts折线图
    QLineSeries *series = new QLineSeries();

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("每日完成任务数：");

    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //到此为止，qchart折线图初始化完毕

    this->setMinimumSize(1000,600);
    on_actiona_triggered();

    connectDB();//打开数据库

    intitData();//设置重要性下拉菜单

  
    connect(ui->tableView,&table::releaseSign,this,&MainWindow::wetherComplit);  //设置右键点击显示对话框
    connect(ui->tableView_2,&table::releaseSign,this,&MainWindow::complited);    //同上
   
    connect(&m_start,&startui::login_start,[=](){//测试初始登录界面
        m_login.show();
    });
    connect(&m_start,&startui::sign_start,[=](){
        m_sign.show();
    });
    connect(&m_login,&login::checkStart,[=](){
        table_name =  m_logincheck();
    });
    connect(&m_sign,&signup::checkStart,[=](){
        table_name = m_signcheck();
    });
    connect(this,&MainWindow::appStart,[=](){
        m_sign.close();
        show();
    });
    connect(this,&MainWindow::appStart,[=](){
        m_login.close();
        show();
    });
    if(!system_db.open()){
        connectUSER();
    }
    system_db.open();
    m_start.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//饼状图的初始化函数
void MainWindow::createpieSewies()
{
    //饼状图
    QPieSeries * my_pieSeries = new QPieSeries();
    //中间圆与大圆的比例
    my_pieSeries->setHoleSize(0.35);
    //扇形及数据
    QPieSlice *pieSlice_running = new QPieSlice();
    pieSlice_running->setValue(25);//扇形占整个圆的百分比
    pieSlice_running->setLabel("XXX");
    pieSlice_running->setLabelVisible();
    pieSlice_running->setColor(QColor("#4cb9cf"));
    pieSlice_running->setLabelColor(QColor("#4cb9cf"));
    pieSlice_running->setBorderColor(QColor("#4cb9cf"));
    pieSlice_running->setBorderColor(QColor());
    my_pieSeries->append(pieSlice_running);

    QPieSlice *pieSlice_noconnect = new QPieSlice();
    pieSlice_noconnect->setValue(25);
    pieSlice_noconnect->setLabel("YYY");
    pieSlice_noconnect->setColor(QColor("#53b666"));
    pieSlice_noconnect->setLabelColor(QColor("#53b666"));
    pieSlice_noconnect->setBorderColor(QColor("#53b666"));
    pieSlice_noconnect->setLabelVisible();//设置标签可见,缺省不可见
    my_pieSeries->append(pieSlice_noconnect);

    QPieSlice *pieSlice_idle = new QPieSlice();
    pieSlice_idle->setValue(50);
    pieSlice_idle->setLabel("WWW");
    pieSlice_idle->setLabelVisible();
    pieSlice_idle->setColor(QColor("#2f89cf"));
    pieSlice_idle->setLabelColor(QColor("#2f89cf"));
    pieSlice_idle->setBorderColor(QColor("#2f89cf"));
    my_pieSeries->append(pieSlice_idle);
    // 图表视图
    QChart *chart = new QChart();
    chart->setTitle("FFFFF");
    chart->addSeries(my_pieSeries);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setBackgroundVisible(false);
    chart->legend()->setFont(QFont("黑体", 8)) ; // 图例字体
    chart->setTitleBrush(QColor("#808396"));
    chart->legend()->setLabelColor(QColor("#808396"));
    QChartView *chartView = new QChartView();
    chartView = new QChartView(ui->graphicsView_3);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRenderHint(QPainter::NonCosmeticDefaultPen);
    chartView->setChart(chart);
    chartView->setMinimumSize(700,300);
    //这下面原来代码是该改列方式，不注视掉的话会将饼状图初始化在主界面上，不知道为啥
    //ui->gridLayout->addWidget(chartView);
}



void MainWindow::wetherComplit(int i){  //未完成界面对话框，确定时将第i行的complit值改成yes

//    QWidget *dlg=new QWidget(this);
//    //dlg->setAttribute(Qt::WA_DeleteOnClose);
//    dlg->setMinimumSize(500,500);
//    QLabel lable(dlg);
//    lable.setText("hello");
//    lable.show();

//    QTextEdit edit(dlg);
//    dlg->show();
//    //qDebug()<<i<<i;

//    QSqlTableModel *model3=new QSqlTableModel(this);
//    model3->setTable("tasks");


    int a=QMessageBox::question(this,"完成","是否完成此项？",
                                QMessageBox::Yes,QMessageBox::No);
    if(a==QMessageBox::Yes){
        QSqlRecord record = model->record(i);
        record.setValue("complit","yes");
        model->setRecord(i,record);

        model->database().transaction();
        model->submitAll();
        //qDebug()<<i;
        //connectDB();
        model->database().commit();
        setModel();
    }
}


//完成界面对话框，确定时将第i行的complit值改成no
void MainWindow::complited(int i){
    int a=QMessageBox::question(this,"未完成","此项还未完成？",
                                QMessageBox::Yes,QMessageBox::No);
    if(a==QMessageBox::Yes){
        QSqlRecord record = model2->record(i);
        record.setValue("complit","no");
        model2->setRecord(i,record);
        model2->database().transaction();
        model2->submitAll();
        model2->database().commit();
        setModel();
    }
}
void MainWindow::on_actiona_triggered()   //学习任务界面
{
    ui->stackedWidget->setCurrentWidget(ui->task);
    ui->toolBox->setCurrentWidget(ui->page_3);
}

void MainWindow::on_actionb_triggered()   //统计界面（未完成）
{
    ui->stackedWidget->setCurrentWidget(ui->calc);
}

void MainWindow::connectUSER(){
    system_db=QSqlDatabase::addDatabase("QSQLITE");
    system_db.setDatabaseName("system.db");

    if(!system_db.open()){
        QMessageBox::warning(this,"错误",system_db.lastError().text());
        return;
    }

    QSqlQuery sql(system_db);
    sql.exec("create table users(username text not null,password text not null)");
    sql.exec("insert into users values ('admin','12345')");
}
//打开数据库
void MainWindow::connectDB(){
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");

    if(!db.open()){
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }

    if(!db.tables().contains("inportance")){
        setInportance();
    }

    QSqlQuery sql(db);
    sql.exec("create table tasks(任务,重要性,开始时间,结束时间,dueTime, completeTime,详情,complit)");//创建数据库，添加新数据项dueTime，completeTime
    setModel();
}
void MainWindow::setInportance(){    //设置重要性表单
    QSqlQuery sql(db);
    sql.exec("create table inportance(inportance)");
    sql.exec("insert into inportance values (\"A\")");
    sql.exec("insert into inportance values (\"B\")");
    sql.exec("insert into inportance values (\"C\")");
    sql.exec("insert into inportance values (\"D\")");
}

void MainWindow::intitData(){//设置下拉框
    QSqlQueryModel *queryModel=new QSqlQueryModel(this);
    queryModel->setQuery("select inportance from inportance");
    ui->comboBox->setModel(queryModel);
}

void MainWindow::on_ok_clicked()
{
    if(!ui->lineEdit->text().isEmpty()&&!ui->textEdit->toPlainText().isEmpty()){
        QSqlQuery sql(db);
        //这里更新了创建项目时的新属性，添加duetime，completetime
        sql.exec("create table tasks(任务,重要性,开始时间,结束时间,dueTime, completeTime,详情)");
        sql.exec(QString("insert into tasks values('%1','%2','%3','%4','%5','%6','%7')")
                 .arg(ui->lineEdit->text()).arg(ui->comboBox->currentText()).arg(ui->dateTimeEdit->dateTime().toString()).arg(ui->dateTimeEdit_2->dateTime().toString()).arg(ui->dateTimeEdit_3->dateTime().toString()).arg(ui->dateTimeEdit_2->dateTime().toString()).arg(ui->textEdit->toPlainText()));

        model=new QSqlTableModel(this);
        model->setTable("tasks");
        ui->tableView->setModel(model);
        //model->removeColumn(3);
        model->select();

        ui->toolBox->setCurrentWidget(ui->page_3);

        on_cansle_clicked();

    }
}
//将数据库显示到tableView中
void MainWindow::setModel(){
    model=new QSqlTableModel(this);
    model2=new QSqlTableModel(this);
    model->setTable("tasks");
    model2->setTable("tasks");

//    model->removeColumn(5);
//    model2->removeColumn(5);


    model->setFilter("complit='no'");
    model->select();
    ui->tableView->setModel(model);


    model2->setFilter("complit='yes'");
    model2->select();
    ui->tableView_2->setModel(model2);
}


//添加任务界面取消按钮
void MainWindow::on_cansle_clicked()
{
    ui->lineEdit->clear();
    ui->textEdit->clear();
    /*添加时间等清除操作*/
}

//void MainWindow::mouseReleaseEvent(QMouseEvent *event){
//    int curRow = ui->tableView->currentIndex().row();
//    qDebug()<<curRow;
//}

QString MainWindow::m_logincheck()
{

if(QueryUserData_1())
    return login::user;
else{
     QMessageBox::warning(&m_login,"错误","账号或密码错误");
     return NULL;
   }
}
QString  MainWindow::m_signcheck(){
if(QueryUserData_2()){
    QSqlQuery sql(system_db);
    sql.exec("insert into users values ("+m_sign.user+","+m_sign.pass+")");
    return m_sign.user;
}
else{
     QMessageBox::warning(&m_login,"错误","用户名已存在！");
     return NULL;
   }
}
bool MainWindow::QueryUserData_2(){
    QSqlQuery sql_query(system_db);
    if(!sql_query.exec("select username from users"))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            QString username = sql_query.value(0).toString();
            if(m_sign.check(username)){
                continue;
            qDebug()<<QString("username:%1).arg(username)");
            }
            else
                return false;
        }
        appStart();
        return true;
    }
}
bool MainWindow::QueryUserData_1()//遍历查询
{
    QSqlQuery sql_query(system_db);
    if(!sql_query.exec("select username,password from users"))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            QString username = sql_query.value(0).toString();
            QString password = sql_query.value(1).toString();
            if(m_login.check(username,password))
                appStart();
                return true;
            qDebug()<<QString("username:%1    password:%2").arg(username).arg(password);
        }
    }
    return false;
}


