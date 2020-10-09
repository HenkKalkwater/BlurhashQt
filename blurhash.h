#ifndef BLURHASH_H
#define BLURHASH_H

#include <cmath>
#include <utility>

#include <QMap>
#include <QQuickImageProvider>
#include <QQuickImageResponse>
#include <QUrlQuery>

#include <QtConcurrent/QtConcurrent>

class BlurHashImageResponse : public QQuickImageResponse {
public:
    BlurHashImageResponse(const QString &id, const QSize &requestedSize);

    QQuickTextureFactory *textureFactory() const override {
        return QQuickTextureFactory::textureFactoryForImage(m_image);
    }

    void failWithError(QString errorMessage) {
        m_errorString = errorMessage;
        emit finished();
    };

    QString errorString() const override { return m_errorString; }


private:
    int decodeBase83(QStringRef ref) const;
    QString m_errorString;
    QImage m_image;
    const static QMap<QChar, int> base83Map;
    static constexpr double pi = 3.1415926;

    QVector<float> decodeDc(int colorEnc) const;
    QVector<float> decodeAc(int colorEnc, float maxAc) const;
    float srgbToLinear(int colorEnc) const;
    int linearToSrgb(float value) const;
};

class BlurHashImageProvider : public QQuickAsyncImageProvider {
public:
    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override;
};

#endif // BLURHASH_H
