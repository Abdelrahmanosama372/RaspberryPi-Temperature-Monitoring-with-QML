import QtQuick
import QtQuick.Effects
import QtCharts 2.6


Window {
    id: rootid
    width: 1200
    height: 600
    visible: true
    title: qsTr("TempHum Monitor")

    property int horioffset: 70
    property int vertioffset: 140




    Rectangle{
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color:  "#28254F" }
            GradientStop { position: 1.0; color:  "#0c1627" }
        }

        Text {
            y: 40
            text: qsTr("Welcome to TempHum Monitor!")
            font.family: "Helvetica";
            font.pointSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#FD673A"

        }


        CustomFrame {
            id: tempFrameid
            x: horioffset
            y: vertioffset
            width: rootid.width/3
            height: rootid.height/1.5
            color: "#28254F"

            CustomDial {
                id: tempdialId
                anchors.horizontalCenter: tempFrameid.horizontalCenter
                width: 300
                height: 300
                dataName: "Temperature"
                dataValue: monitorSystemData.currentTemp + qsTr("\u2103")
                sliderval: parseFloat(monitorSystemData.currentTemp)

                Connections {
                    target: monitorSystemData
                    function onCurrentTempChanged(){
                        tempdialId.dataValue = monitorSystemData.currentTemp + qsTr("\u2103")
                        tempdialId.sliderval = parseFloat(monitorSystemData.currentTemp)
                    }
                }
            }
        }

        CustomFrame {
            id: humidFrameid
            x: rootid.width - humidFrameid.width - horioffset
            y: vertioffset
            width: rootid.width/3
            height: rootid.height/1.5
            color: "#28254F"

            CustomDial {
                id: humiddialId
                anchors.horizontalCenter: parent.horizontalCenter
                width: 300
                height: 300
                dataName: "Humidity"
                dataValue: monitorSystemData.currentHumid + qsTr("%")
                sliderval: parseFloat(monitorSystemData.currentHumid)

                Connections {
                    target: monitorSystemData
                    function onCurrentHumidChanged(){
                        humiddialId.dataValue = monitorSystemData.currentHumid + qsTr("%")
                        humiddialId.sliderval = parseFloat(monitorSystemData.currentHumid)
                    }
                }

            }

        }

    }

}





