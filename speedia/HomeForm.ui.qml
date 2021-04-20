import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    property alias button: newSearch

    title: qsTr("Home")

    Image {
        id: image
        x: 203
        y: 23
        width: 195
        height: 111
        horizontalAlignment: Image.AlignHCenter
        source: "img/car.png"
        layer.wrapMode: ShaderEffectSource.ClampToEdge
        autoTransform: false
        fillMode: Image.PreserveAspectFit
    }
    Label {
        width: 87
        height: 27
        text: qsTr("Speedia")
        font.pointSize: 17
        anchors.verticalCenterOffset: -115
        anchors.horizontalCenterOffset: 6
        anchors.centerIn: parent
    }

    Rectangle {
        id: rectangle
        x: 193
        y: 205
        width: 215
        height: 81
        color: "#4cffffff"
        radius: 38
        anchors.topMargin: parent.padding
    }
    Text {
        id: text1
        x: 203
        y: 220
        width: 195
        height: 72
        text: qsTr("Find your next used car through Speedia! Click the top left menu to view the Search and Results Page or click below for a new search.")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
    }

    Button {
        id: newSearch
        x: 249
        y: 325
        text: qsTr("New Search")

        Connections {
            target: newSearch
            onClicked: stackView.push("Search.ui.qml")
        }
    }

}


