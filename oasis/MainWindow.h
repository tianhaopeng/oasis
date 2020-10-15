#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QFileInfo>
#include <QProcess>
#include <QTcpSocket>

#include <QBitmap>
#include <QPainter>
#include <QTimer>

#include "Login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *);
    bool eventFilter(QObject *target, QEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    ~MainWindow();
    void PixmapToRound(QPixmap *src);
    QPixmap PixmapToRound(const QPixmap &src, int radius);

private:
    void init();
    void initConnect();

    Ui::MainWindow *ui;
    QString name, user;
    double slider = 1.0;
    QTcpSocket *socket;
    QByteArray img;
    int nowSize = 0;
    QProcess process;
    QTimer *timer;
    int canHide = 0;
};
#endif // MAINWINDOW_H
