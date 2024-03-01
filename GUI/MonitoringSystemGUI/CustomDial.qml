import QtQuick
import QtQuick.Effects

Item {

    width: mainrecid.width
    height: mainrecid.height
    property double sliderval: -Math.PI / 2;
    property alias dataName: datanameid.text
    property alias dataValue: datavalid.text


    Rectangle{
        id: mainrecid
        width: parent.width
        height: parent.height
        radius: mainrecid.width/2
        y: 30
        // anchors.horizontalCenter: parent.horizontalCenter
        color: Qt.rgba(0,0,0,0.5)

        layer.enabled: true
        layer.effect: MultiEffect {
            source: mainrecid
            anchors.fill: mainrecid
            shadowBlur: 1.0
            shadowEnabled: true
            shadowColor: Qt.rgba(255, 255, 255, 0.6)
            shadowVerticalOffset: -5
            shadowHorizontalOffset: -5
        }

        Rectangle{
            id: maininnerrecid
            anchors.centerIn: mainrecid
            width: mainrecid.width - 3
            height: mainrecid.width - 3
            radius: (mainrecid.width - 5)/2
            color: "#28254F"
            clip: true
            property int centerX: x + width / 2
            property int centerY: y + height / 2
            property real filll: 0

            Canvas {
                id: sliderid
                anchors.fill: parent
                onPaint: {
                    let ctx = getContext("2d");
                    ctx.clearRect(0, 0, width, height);
                    let radius = maininnerrecid.radius - 15
                    let centerX = width / 2;
                    let centerY = height / 2;
                    let startAngle = -Math.PI / 2;
                    let endAngle = 2*Math.PI * sliderval / 100 - Math.PI /2
                    ctx.beginPath();
                    ctx.arc(centerX, centerY, radius, startAngle, endAngle,);
                    ctx.lineWidth = 30;
                    ctx.strokeStyle = "#FD673A";
                    ctx.stroke();
                }
            }
        }


        Rectangle{
            id: middlerecID
            anchors.centerIn: parent
            width: maininnerrecid.width - 48
            height: width
            radius: width/2
            color: Qt.rgba(0,0,0,0.5)

            Rectangle{
                id: innerID
                anchors.centerIn: parent
                width: maininnerrecid.width - 50
                height: width
                radius: width/2
                color: "blue"


                gradient: Gradient {
                    GradientStop { position: 0.0; color:  "#28254F" }
                    GradientStop { position: 1.0; color:  "#0c1627" }
                    orientation: Gradient.AfricanField
                }

                Text {
                    id: datavalid
                    text: qsTr("25")
                    anchors.centerIn: parent
                    color: "white"
                    font.family: "Helvetica";
                    font.pointSize: 20;
                    font.bold: true
                }
                Text {
                    id: datanameid
                    anchors.top: datavalid.bottom
                    anchors.horizontalCenter: parent.horizontalCenter

                    text: qsTr("Temperature")
                    color: "white"
                    font.family: "Helvetica";
                    font.pointSize: 10;
                    font.bold: true
                }
            }
        }

    }

    onSlidervalChanged: {
        sliderid.requestPaint()
    }
}
