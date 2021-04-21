import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0

Page {
    width: 820
    height: 400
    property alias button: newSearch

    title: qsTr("Home")

    Image {
        id: image
        x: 313
        y: 15
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
        anchors.verticalCenterOffset: -129
        anchors.horizontalCenterOffset: 13
        anchors.centerIn: parent
    }

    Rectangle {
        id: rectangle
        x: 303
        y: 182
        width: 215
        height: 81
        color: "#4cffffff"
        radius: 38
        anchors.topMargin: parent.padding
    }
    Text {
        id: text1
        x: 313
        y: 196
        width: 195
        height: 72
        text: qsTr("Find your next used car through Speedia! Click the top left menu to view the Search and Results Page or click below for a new search.")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
    }

    Button {
        id: newSearch
        x: 359
        y: 300
        text: qsTr("New Search")

        Connections {
            target: newSearch
            onClicked: stackView.push("Search.ui.qml")
        }
    }

    ColumnLayout {
    }

}


