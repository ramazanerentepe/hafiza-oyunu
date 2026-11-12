#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMap>
#include <QSet>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void kartTiklandi();
    void sureyiGuncelle();

private:
    Ui::MainWindow *ui;
    QList<QPushButton*> kartlar;
    QMap<QPushButton* , QString> resimler;
    const QString arkaResim = ":/img/images/arka.png" ;
    QPushButton *ilkKart = nullptr;
    QSet<QPushButton*> eslesenler;
    bool bekleme = false;
    int basarisizSayac = 0;
    QTimer *sureSayaci;
    int saniye = 0;
    int salise = 0;

    bool bittiMi() const;
};
#endif // MAINWINDOW_H
