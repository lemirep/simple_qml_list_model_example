#ifndef CARMODEL_H
#define CARMODEL_H

#include "ListItem.h"

class CarModel : public Models::ListItem
{
    Q_OBJECT


    Q_PROPERTY(QString carName WRITE setCarName CONSTANT)
    Q_PROPERTY(QString carBrand WRITE setCarBrand CONSTANT)
    Q_PROPERTY(int carPrice WRITE setCarPrice CONSTANT)


public:
    explicit CarModel(QObject *parent = NULL);
    explicit CarModel(int id, const QString &name, const QString &brand, int price, QObject *parent = NULL);

    // ListItem interface
    enum CarEnum
    {
        car_name = Qt::UserRole + 1,
        car_brand,
        car_price,
        car_id
    };


public:
    int id() const;
    QVariant data(int role) const;
    bool setData(int role, const QVariant &value);
    QHash<int, QByteArray> roleNames() const;

    void setCarName(const QString &carName);
    void setCarBrand(const QString &carBrand);
    void setCarPrice(int price);

private:
    int     carId;
    QString name;
    QString brand;
    int     price;

};

#endif // CARMODEL_H
