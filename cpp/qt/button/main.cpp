#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton myButton(QIcon::fromTheme("edit-undo"), "Push me");
    myButton.setToolTip("Click this to turn the back the hands of time.!");
    myButton.show();
}
