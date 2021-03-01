#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{

    /* Uncomment if compiled for embedded device with wayland compositor
    qputenv("XDG_RUNTIME_DIR", "/opt/waylandCompositor");
    qputenv("QT_QPA_PLATFORM", "wayland");
    */

    /* Uncomment if compiled for eglfs environment
    qputenv("QT_QPA_EGLFS_ALWAYS_SET_MODE","1");
    qputenv("QT_QPA_EGLFS_KMS_ATOMIC","1");
    qputenv("QT_QPA_PLATFORM", "eglfs");
    */
    qputenv("QSG_INFO", "1");
    qputenv("QT_OPENGL", "angle");
    qputenv("QSG_RENDER_LOOP","threaded");
 /*

*/
    QGuiApplication::setAttribute(Qt::AA_UseOpenGLES);
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    switch (QOpenGLContext::openGLModuleType()) {
    case QOpenGLContext::LibGLES:
        qDebug() << "OpenGL context: LibGLES";
        break;
    case QOpenGLContext::LibGL:
        qDebug() << "OpenGL context: LibGLES";
        break;
    }


    QPalette newPalette;
    newPalette.setColor(QPalette::Window,          QColor( 37,  37,  37));
    newPalette.setColor(QPalette::WindowText,      QColor(212, 212, 212));
    newPalette.setColor(QPalette::Base,            QColor( 60,  60,  60));
    newPalette.setColor(QPalette::AlternateBase,   QColor( 45,  45,  45));
    newPalette.setColor(QPalette::PlaceholderText, QColor(127, 127, 127));
    newPalette.setColor(QPalette::Text,            QColor(212, 212, 212));
    newPalette.setColor(QPalette::Button,          QColor( 45,  45,  45));
    newPalette.setColor(QPalette::ButtonText,      QColor(212, 212, 212));
    newPalette.setColor(QPalette::BrightText,      QColor(240, 240, 240));
    newPalette.setColor(QPalette::Highlight,       QColor( 38,  79, 120));
    newPalette.setColor(QPalette::HighlightedText, QColor(240, 240, 240));

    newPalette.setColor(QPalette::Light,           QColor( 60,  60,  60));
    newPalette.setColor(QPalette::Midlight,        QColor( 52,  52,  52));
    newPalette.setColor(QPalette::Dark,            QColor( 30,  30,  30) );
    newPalette.setColor(QPalette::Mid,             QColor( 37,  37,  37));
    newPalette.setColor(QPalette::Shadow,          QColor( 0,    0,   0));

    newPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));

    qApp->setPalette(newPalette);

    MainWindow w;
    w.show();

    return a.exec();
}
