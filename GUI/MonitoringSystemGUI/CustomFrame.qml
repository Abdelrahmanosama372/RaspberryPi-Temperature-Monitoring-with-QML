import QtQuick
import QtQuick.Effects

Item {
    width: frame1Id.width
    height: frame1Id.height
    property alias color: frame1Id.color

    Rectangle {
        id: frame1Id
        width: parent.width
        height: parent.height
        color: "#28254F"
        radius: 10
        layer.enabled: true
        layer.effect: MultiEffect {
            source: frame1Id
            anchors.fill: frame1Id
            shadowBlur: 1.0
            shadowEnabled: true
            shadowColor: Qt.rgba(255, 255, 255, 0.5)
            shadowVerticalOffset: -5
            shadowHorizontalOffset: -5
        }
    }
}
