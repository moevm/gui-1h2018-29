#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>

#include "themesmodel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    //Theme th("words", "learn words", taskL);

   // ThemesModel *model = new ThemesModel();

    //model->append(th);

    QList<QObject*> dataList;
    dataList.append(new Theme("words", "learn words"));
    dataList.append(new Theme("test", "learn test"));
    dataList.append(new Theme("read", "learn read"));


    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    QQmlContext *ctxt = view.rootContext();
//    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));

    //engine.setContextForObject(QVariant::fromValue(dataList), "myModel");

    return app.exec();
}
