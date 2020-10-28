#include "blurhash_plugin.h"

#include "blurhash.h"

#include <qqml.h>

void BlurhashPlugin::registerTypes(const char *uri) {
    // @uri nl.netsoj.chris.blurhash
    Q_UNUSED(uri)
    qmlRegisterType<BlurhashDummy>(uri, 1, 0, "BlurhashDummy");
}

void BlurhashPlugin::initializeEngine(QQmlEngine *engine, const char *uri) {
    Q_UNUSED(uri)
    engine->addImageProvider("blurhash", new BlurHashImageProvider);
}

