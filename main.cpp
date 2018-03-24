#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtQuick>
#include <QQuickItem>
#include <QQuickView>
#include <string>

#include "taskelement.h"
#include "theme.h"
#include "themesmodel.h"
#include "controller.h"


int main(int argc, char *argv[])
{
    ThemesModel *model = new ThemesModel();
    QList<QObject*> objects=model->getThemesList();
    QList<Theme*> themes;
    themes.append(qobject_cast<Theme*>(objects.at(0)));
    themes.append(qobject_cast<Theme*>(objects.at(1)));
    qDebug()<<themes.at(0)->getThemeName();
    qDebug()<<themes.at(1)->getThemeName();
}
//int main(int argc, char *argv[])
//{
//#if defined(Q_OS_WIN)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    //Theme th("words", "learn words", taskL);

//   // ThemesModel *model = new ThemesModel();

//    //model->append(th);

//    QList<QObject*> dataList;
//    QList<Theme*> modelList;

//    Theme *t1 = new Theme("words", "learn words");

//    TaskElement *te1 = new TaskElement("qwe", 1);
//    TaskElement *te2 = new TaskElement("asd", 2);
//    TaskElement *te3 = new TaskElement("zxc", 3);

//    QList<QObject*> lst = {te1, te2, te3};

//    t1->setListOfTasks(lst
//                       );
//    dataList.append(t1);
//    dataList.append(new Theme("test", "learn test"));
//    dataList.append(new Theme("read", "learn read"));

//    modelList.append(t1);
//    modelList.append(new Theme("test", "learn test"));
//    modelList.append(new Theme("read", "learn read"));




//    QGuiApplication app(argc, argv);
//    QQmlApplicationEngine engine;
//    QQmlContext *ctxt = engine.rootContext();
//    Controller *controller = new Controller(modelList);

//    QObject* context_list = new QObject();

//    ctxt->setContextProperty("controller", controller);
//    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
//    ctxt->setContextProperty("ctxList", context_list);
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/TaskForm.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/StudyTab.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

//    QQuickView view(QUrl::fromLocalFile("qrc:/StudyTab.qml"));
//    QObject *item = view.rootObject();

//    //QObject *item = qobject_cast<QQuickItem*>(view.rootObject());


//    //Controller::connect(item, SIGNAL(qmlSignal(QString)), controller, SLOT(findTheme(QString)));


//    QObject::connect(item, SIGNAL(qmlSignal(QVariant)),
//                         controller, SLOT(cppSlot(QVariant)));


//    return app.exec();
//}
