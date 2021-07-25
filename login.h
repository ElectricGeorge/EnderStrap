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
    void updateProgress(int percent, bool done);

private slots:
    void launch();

private:
    Ui::LoginWindow* ui;
};

