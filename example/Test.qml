 import QtQuick 2.7
 import QtQuick.Controls 2.7
 
 import nl.netsoj.chris.blurhash 1.0
 
 Column {
	 width: 400
	 TextField {
		id: blurHashText
		placeholderText: "Enter blurhash"
		text: "KEHV6nWB2ypyoJad.7kCMd"
	}
	
	Text {
		visible: image.status == Image.Error
		text: "Image error. Blurhash length: " + blurHashText.text.length
	}
	
	Text {
		text: "Punch: " + punch.value
	}
	
	Slider {
		id: punch
		width: parent.width
		from: 0
		to: 1
		value: 1
	}
	
	Image {
		id: image
		width: parent.width
		height: width / 3 * 2
		source: "image://blurhash/" + encodeURIComponent(blurHashText.text) + "?punch=" + punch.value
		//sourceSize.width: image.width
		//sourceSize.height: image.height
	}
}
