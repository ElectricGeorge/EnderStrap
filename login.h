#include <QMainWindow>

namespace Ui
{
    class LoginWindow;
} // namespace Ui

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void setUsername();
    void setPassword();
    void exit();
    void launch();

private:
    Ui::LoginWindow* ui;
};

