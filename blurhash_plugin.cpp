#include "blurhash_plugin.h"

#include "blurhash.h"

#include <qqml.h>

void initializeEngine(QQmlEngine *engine, const char *uri) {
    Q_UNUSED(uri)
    // @uri nl.netsoj.chris.blurhash
    //qmlRegisterType<BlurHash>(uri, 1, 0, "BlurHash");
    engine->addImageProvider("blurhash", new BlurHashImageProvider);
}

