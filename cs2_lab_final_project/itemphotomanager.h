#ifndef ITEMPHOTOMANAGER_H
#define ITEMPHOTOMANAGER_H

#include <QString>
#include <QPixmap>
#include <QMap>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QStandardPaths>

class ItemPhotoManager
{
public:
    static ItemPhotoManager& getInstance();

    // Configuration
    static void setPhotoDirectory(const QString& path);
    static QString getPhotoDirectory();

    // Photo management functions
    bool saveItemPhoto(const QString& itemName, const QString& photoPath);
    QPixmap getItemPhoto(const QString& itemName);
    bool deleteItemPhoto(const QString& itemName);
    bool addPhoto(const QString& itemName, const QString& photoPath);
    QPixmap getPhoto(const QString& itemName);
    bool hasPhoto(const QString& itemName);
    bool removePhoto(const QString& itemName);

private:
    ItemPhotoManager();
    ~ItemPhotoManager();
    ItemPhotoManager(const ItemPhotoManager&) = delete;
    ItemPhotoManager& operator=(const ItemPhotoManager&) = delete;

    QString getPhotoPath(const QString& itemName);
    void loadExistingPhotos();

    QDir photosDir;
    QMap<QString, QString> photoPaths; // Maps item names to their photo paths
    static QString customPhotoDir; // For storing custom directory path
};

#endif // ITEMPHOTOMANAGER_H
