#include <QApplication>            // Methods used => QApplication
#include "PaymentSystemWindow.hpp" // Methods used => PaymentSystemWindow
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PaymentSystemWindow window;
    window.show();

    return app.exec();
}
