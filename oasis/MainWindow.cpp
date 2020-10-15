#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    initConnect();
}

MainWindow::~MainWindow()
{
    socket->write("q");
    socket->waitForBytesWritten();
    process.close();
    delete socket;
    delete ui;
}


void MainWindow::init()
{
    Login login;
    login.get(&name,&user);
    ui->id->setText(QString("User Name:%1<br>Patient ID:%2").arg(name).arg(user));
    ui->LOGO->installEventFilter(this);
    QFileInfo fi("video_image");
    if(!fi.isDir()) {
        QDir d;
        d.mkdir("video_image");
    }

    timer = new QTimer;
    timer->setInterval(2000);

    process.start("python",QStringList{"opencv.py"});
    process.waitForStarted();
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1",5599);
    socket->waitForConnected();
    socket->write(QString(name+"~*~"+user).toUtf8());
    socket->waitForBytesWritten();

    timer->start();
}

void MainWindow::initConnect()
{
    connect(ui->btn1,&QPushButton::clicked,[=]{
        socket->write("1");
    });
    connect(ui->btn2,&QPushButton::clicked,[=]{
        socket->write("2");
    });
    connect(ui->btn3,&QPushButton::clicked,[=]{
        QDesktopServices::openUrl(QUrl("video_image"));
    });
    connect(ui->slider,&QScrollBar::valueChanged,[=]{
//        slider = (100 - ui->slider->value()) / 100.0;
        socket->write(QString("slider"+QString::number(ui->slider->value())).toUtf8());
    });
    connect(socket,&QTcpSocket::readyRead,[=]{
        if(nowSize == 0){
            nowSize = socket->readAll().toInt();
        } else {
            img.append(socket->readAll());
            if(img.size() == nowSize){
                nowSize = 0;
                QPixmap imgp;
                imgp.loadFromData(img);
                img.clear();
                QPixmap imgs = imgp.scaled(ui->video->size());
//                PixmapToRound(&imgs);
                ui->video->setPixmap(imgs);
            }
        }
    });
    connect(timer,&QTimer::timeout,[=]{
        canHide++;
        if(canHide == 2){
            ui->frame->resize(20, this->height());
//            int videoX = (int(this->width()*0.8) - this->height() - 20) / 2 + 20, h = this->height() / 2;
//            ui->video->setGeometry(videoX,0,this->height(),this->height());
//            ui->video->setStyleSheet(QString("QLabel{border-radius: %1px;background-color: #fffbbd;}").arg(h));
        }
    });
}
void MainWindow::resizeEvent(QResizeEvent *)
{
    canHide = 0;
    QSize root = this->size();
    ui->frame->resize(int(root.width()*0.2),root.height());
    QSize frame = ui->frame->size();
    ui->LOGO->resize(frame.width(),int(frame.width()/2.5));
    ui->LOGO->setPixmap(QPixmap("LOGO.png").scaled(ui->LOGO->size()));
    ui->slider->setGeometry(int(frame.width()*0.2),frame.height()-50,int(frame.width()*0.6),30);
    ui->sub->setGeometry(int(frame.width()*0.2),frame.height()-80,int(frame.width()*0.1),30);
    ui->zoom->setGeometry(int(frame.width()*0.3),frame.height()-80,int(frame.width()*0.4),30);
    ui->add->setGeometry(int(frame.width()*0.7),frame.height()-80,int(frame.width()*0.1),30);
    ui->btn1->setGeometry(int(frame.width()*0.2),int(frame.height()*0.2),int(frame.width()*0.6),int(frame.width()*0.18));
    ui->btn2->setGeometry(int(frame.width()*0.2),int(frame.height()*0.35),int(frame.width()*0.6),int(frame.width()*0.18));
    ui->btn3->setGeometry(int(frame.width()*0.2),int(frame.height()*0.5),int(frame.width()*0.6),int(frame.width()*0.18));
    ui->btn4->setGeometry(int(frame.width()*0.2),int(frame.height()*0.65),int(frame.width()*0.6),int(frame.width()*0.18));
    ui->id->setGeometry(int(root.width()*0.8),20,int(root.width()*0.2),int(root.height()*0.1));
//    int videoX = (int(root.width()*0.6) - int(root.height()*0.8)) / 2 + int(root.width()*0.2);
//    ui->video->setGeometry(videoX,int(root.width()*0.1),int(root.height()*0.8),int(root.height()*0.8));
//    ui->video->setStyleSheet(QString("QLabel{border-radius: %1px;background-color: #fffbbd;}").arg(ui->video->height()/2));
    ui->video->resize(this->size());
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->LOGO && event->type() == QEvent::MouseButtonRelease){
        if(ui->frame->width() == 20){

        }else{

        }
    }
    return QWidget::eventFilter(target,event);
}

void MainWindow::PixmapToRound(QPixmap *src)
{
    int s = src->width(), ra = s / 2;
    QSize size(s, s);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, s, s, Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, s, s, ra, ra);
    src->setMask(mask);
}

QPixmap MainWindow::PixmapToRound(const QPixmap &src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QSize size(2*radius, 2*radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 120, 120);
    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}



void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    canHide = 0;
    ui->frame->resize(int(this->width()*0.2), this->height());
//    int videoX = (int(this->width()*0.6) - int(this->height()*0.8)) / 2 + int(this->width()*0.2);
//    ui->video->setGeometry(videoX,int(this->width()*0.1),int(this->height()*0.8),int(this->height()*0.8));
//    ui->video->setStyleSheet(QString("QLabel{border-radius: %1px;background-color: #fffbbd;}")
//                             .arg(ui->video->height()/2));
}
