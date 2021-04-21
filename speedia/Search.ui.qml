import QtQuick 2.12
import QtQuick.Controls 2.12
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.0

Page {
    id: page
    width: 820
    height: 400

    title: qsTr("Search")
    property var treeType: ""

    BackEnd {
        id: backend
    }

    ComboBox {
        id: comboBox
        x: 272
        y: 135
        width: 276
        height: 43
        model: ["Car Brand", "Audi", "BMW", "Hyundai", "Mercedes", "Skoda","Toyota",  "Vauxhall", "Volkswagen" ]

        onCurrentTextChanged: backend.brand = comboBox.currentText
    }

    ColumnLayout {
        x: 360
        y: 192
        spacing: 2


        RadioButton {
            id: avl
            text: qsTr("AVL Tree")
            onClicked: treeType = "avl"
        }

        RadioButton {
            id: bst
            text: qsTr("BST")
            onClicked: treeType = "bst"
        }
    }


    ColumnLayout {
        x: 238
        y: 23

        Slider {
            id: priceSlider
            Layout.preferredHeight: 48
            Layout.preferredWidth: 344
            stepSize: 100
            live: true
            value: 0
            to: 200000

            onPressedChanged: backend.price = priceSlider.value


            Connections {
                target: priceSlider
                onMoved: price.text = "$" + priceSlider.value
            }

            Label {
                id: priceLabel
                x: 8
                y: 0
                text: qsTr("Max Price")
            }

            Label {
                id: price
                x: 307
                y: 0
                width: 29
                height: 17
                text: priceSlider.value
                horizontalAlignment: Text.AlignRight
            }
        }

        Slider {
            id: mileageSlider
            Layout.preferredHeight: 48
            Layout.preferredWidth: 344
            stepSize: 100
            value: 0
            to: 400000

            onPressedChanged: backend.mileage = mileageSlider.value

            Label {
                id: mileageLabel
                x: 8
                y: -3
                text: qsTr("Max Mileage")
            }

            Label {
                id: mileage
                x: 279
                y: -3
                width: 57
                height: 17
                text: mileageSlider.value
                horizontalAlignment: Text.AlignRight
            }

            Connections  {
                target: mileageSlider
                onMoved: mileage.text = mileageSlider.value
            }



        }
    }


    Button {
        id: searchButton
        x: 356
        y: 318
        width: 108
        height: 55
        text: qsTr("Search!")
        Layout.preferredHeight: 74
        Layout.preferredWidth: 175


        Connections {
            target: searchButton
            onClicked: {
                backend.searchTree = treeType
                textArea.text = backend.getResults() + "\n"
                page.state = "results"
            }
        }
    }

    ScrollView {
            id: scrollView
            anchors.fill: parent
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 1
            visible: false

            TextArea {
                id: textArea
                wrapMode: "WordWrap"
            }

        }

    states: [
        State {
            name: "results"

            PropertyChanges {
                target: comboBox
                visible: false
            }

            PropertyChanges {
                target: mileageSlider
                visible: false
            }

            PropertyChanges {
                target: priceSlider
                visible: false
            }

            PropertyChanges {
                target: avl
                visible: false
            }

            PropertyChanges {
                target: bst
                visible: false
            }

            PropertyChanges {
                target: searchButton
                visible: false
            }
            PropertyChanges {
                target: scrollView
                visible: true
                contentWidth: 50
            }

            PropertyChanges {
                target: textArea
                width: 820
                height: 430
                wrapMode: Text.WordWrap
                textFormat: Text.PlainText
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
