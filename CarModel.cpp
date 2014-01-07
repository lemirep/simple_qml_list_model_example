#include "CarModel.h"
#include <QDebug>
// USE THIS CONSTRUCTOR ONLY TO PROVIDE PROTOTYPE FOR MODEL CONSTRUCTOR
CarModel::CarModel(QObject *parent) : Models::ListItem(parent)
{
}

CarModel::CarModel(int id, const QString &name, const QString &brand, int price, QObject *parent) : Models::ListItem(parent),
    carId(id),
    name(name),
    brand(brand),
    price(price)
{
}

int CarModel::id() const
{
    return this->car_id;
}

QVariant CarModel::data(int role) const
{
    switch(role)
    {
    case car_name:
        return this->name;
    case car_brand:
        return this->brand;
    case car_price:
        return this->price;
    case car_id:
        return this->id();
    default :
        QVariant();
    }
}

bool CarModel::setData(int role, const QVariant &value)
{
    switch(role)
    {
    case car_name:
        this->name = value.toString();
        // TO REFRESH MODEL
        this->triggerItemUpdate();
        return true;
    case car_brand:
        this->brand = value.toString();
        // TO REFRESH MODEL
        this->triggerItemUpdate();
        return true;
    case car_price:
        this->price = value.toInt();
        // TO REFRESH MODEL
        qDebug() << "Price Changed" << this->price;
        this->triggerItemUpdate();
        return true;
    default :
        return false;
    }
}

// ASSIGN THE NAME TO USE FROM QML SIDE TO ACCESS VALUES
QHash<int, QByteArray> CarModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[car_name] = "car_name";
    roles[car_brand] = "car_brand";
    roles[car_price] = "car_price";
    roles[car_id] = "car_id";
    return roles;
}

void CarModel::setCarName(const QString &carName)
{
    this->name = carName;
}

void CarModel::setCarBrand(const QString &carBrand)
{
    this->brand = carBrand;
}

void CarModel::setCarPrice(int price)
{
    this->price = price;
}

