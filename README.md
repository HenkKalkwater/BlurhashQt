# qt-blurhash
Blurhash ImageProvider for Qt. Based on https://github.com/woltapp/blurhash.

If you're asking: What's blurhash? [Visit this website, it explains more than I could do in this readme](https://blurha.sh/) 

## Usage
Register the ImageProvider. You can use it in your qml code like this:
```qml
Image {
    source: "image://blurhash/eACjR;00?aRQ-qD+i?%jx]NYI}%0ISX8rX4.-:a1kEIUrpN2o|WYw["
}
```
## Why did you create this. Don't there already exists implementations of this?
Yes, and they're licensed under the GPLv3. I wanted to use something in a project
I had licensed under the LGPLv2. The GPL is great, isn't it? Anyway, I don't care too much about it,
that's why it's under the MIT.
