#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class TitleWindow;
}

class TitleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TitleWindow(QWidget *parent = nullptr);
    ~TitleWindow();

private slots:
    //function to link our windows together:

    void on_pushButton_clicked();

private:
    Ui::TitleWindow *ui;
};

#endif // TITLEWINDOW_H
