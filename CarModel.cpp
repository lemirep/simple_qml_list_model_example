#include "CarModel.h"

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

