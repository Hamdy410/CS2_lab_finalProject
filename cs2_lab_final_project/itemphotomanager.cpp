#include "itemphotomanager.h"
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QCoreApplication>

QString ItemPhotoManager::customPhotoDir;

ItemPhotoManager& ItemPhotoManager::getInstance()
{
    static ItemPhotoManager instance;
    return instance;
}

void ItemPhotoManager::setPhotoDirectory(const QString& path)
{
    customPhotoDir = path;
    getInstance().photosDir = QDir(path);
    if (!getInstance().photosDir.exists())
    {
        getInstance().photosDir.mkpath(".");
    }
}

QString ItemPhotoManager::getPhotoDirectory()
{
    return customPhotoDir.isEmpty() ?
               getInstance().photosDir.absolutePath() :
               customPhotoDir;
}

ItemPhotoManager::ItemPhotoManager()
{
    // Using custom directory if set, otherwise use default app data location
    if (!customPhotoDir.isEmpty())
    {
        photosDir = QDir(customPhotoDir);
    }
    else
    {
        QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        photosDir = QDir(appDataPath + "/item_photos");
    }

    if (!photosDir.exists())
    {
        if (!photosDir.mkpath("."))
        {
            qDebug() << "Failed to create photos directory:" << photosDir.path();
        }
    }

    // Load existing photo mappings
    loadExistingPhotos();
}

ItemPhotoManager::~ItemPhotoManager()
{
    // Save photo mappings
    QJsonObject json;
    QJsonArray mappings;

    for (auto it = photoPaths.begin(); it != photoPaths.end(); ++it)
    {
        QJsonObject mapping;
        mapping["itemName"] = it.key();
        mapping["photoPath"] = it.value();
        mappings.append(mapping);
    }

    json["photoMappings"] = mappings;

    QFile file(photosDir.filePath("photo_mappings.json"));
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(QJsonDocument(json).toJson());
        file.close();
    }
}

void ItemPhotoManager::loadExistingPhotos()
{
    QFile file(photosDir.filePath("photo_mappings.json"));
    if (file.open(QIODevice::ReadOnly))
    {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (doc.isObject())
        {
            QJsonObject json = doc.object();
            QJsonArray mappings = json["photoMappings"].toArray();

            for (const QJsonValue& value : mappings)
            {
                QJsonObject mapping = value.toObject();
                QString itemName = mapping["itemName"].toString();
                QString photoPath = mapping["photoPath"].toString();

                // Only add if the photo file still exists
                if (QFile::exists(photoPath))
                {
                    photoPaths[itemName] = photoPath;
                }
            }
        }
    }
}

QString ItemPhotoManager::getPhotoPath(const QString& itemName)
{
    return photosDir.filePath(itemName + ".jpg");
}

bool ItemPhotoManager::saveItemPhoto(const QString& itemName, const QString& photoPath)
{
    QImage sourceImage(photoPath);
    if (sourceImage.isNull())
    {
        qDebug() << "Failed to load source image:" << photoPath;
        return false;
    }

    QString targetPath = getPhotoPath(itemName);
    if (!sourceImage.save(targetPath, "JPG", 90))
    {
        qDebug() << "Failed to save image to:" << targetPath;
        return false;
    }

    photoPaths[itemName] = targetPath;
    return true;
}

QPixmap ItemPhotoManager::getItemPhoto(const QString& itemName)
{
    QString photoPath = getPhotoPath(itemName);
    QPixmap photo;

    if (QFile::exists(photoPath))
    {
        photo.load(photoPath);
    }

    return photo;
}

bool ItemPhotoManager::addPhoto(const QString& itemName, const QString& photoPath)
{
    return saveItemPhoto(itemName, photoPath);
}

QPixmap ItemPhotoManager::getPhoto(const QString& itemName)
{
    return getItemPhoto(itemName);
}

bool ItemPhotoManager::hasPhoto(const QString& itemName)
{
    return photoPaths.contains(itemName) && QFile::exists(photoPaths[itemName]);
}

