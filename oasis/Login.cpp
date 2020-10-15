#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->LOGO->setPixmap(QPixmap("LOGO.png").scaled(ui->LOGO->size()));
    connect(ui->btnSure,&QPushButton::clicked,[=]{
        if(!ui->textName->text().isEmpty() && !ui->textUser->text().isEmpty()){
            this->close();
        }
    });
}

Login::~Login()
{
    delete ui;
}

void Login::get(QString *name, QString *user)
{
    this->exec();
    *name = ui->textName->text();
    *user = ui->textUser->text();
}
