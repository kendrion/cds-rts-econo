#ifndef CMPSPLASHSCREEN_QT_H
#define CMPSPLASHSCREEN_QT_H

#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>


class CustomWindow : public QWidget
{
    Q_OBJECT

public:
    static CustomWindow* instance()
    {
        static CustomWindow instance;
        return &instance;
    }

    virtual ~CustomWindow() = default;

private slots:
    void UpdateDateAndTime();

private:
    CustomWindow();

    QLabel _name;
    QLabel _dateTime;
    QLabel _version;
    QTimer _timer;
    QVBoxLayout _layout;
};


#endif //CMPSPLASHSCREEN_QT_H
