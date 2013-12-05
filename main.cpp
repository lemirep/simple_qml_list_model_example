#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include "ListModel.h"
#include "CarModel.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(new QGuiApplication(argc, argv));
    QQuickView *viewer = new QQuickView();
    QQmlContext *context = viewer->rootContext();


    Models::ListModel *carModel = new Models::ListModel(new CarModel());

    carModel->appendRow(new CarModel(0, "Corvette", "Chevrolet", 50000));
    carModel->appendRow(new CarModel(0, "Charger", "Dodge", 25000));
    carModel->appendRow(new CarModel(0, "Mustang", "Ford", 22000));
    carModel->appendRow(new CarModel(0, "F150", "Ford", 50000));
    carModel->appendRow(new CarModel(0, "RAM 1500", "Dodge", 23000));
    carModel->appendRow(new CarModel(0, "Camaro", "Chevrolet", 25000));

    context->setContextProperty("myCarModel", carModel);

    viewer->setSource(QUrl("./main.qml"));
    viewer->show();

    return app->exec();
}
