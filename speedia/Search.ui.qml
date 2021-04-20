import QtQuick 2.12
import QtQuick.Controls 2.12
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.0

Page {
    id: page
    width: 600
    height: 400

    title: qsTr("Search")


    BackEnd {
      id: backend
    }

    Slider {
        id: priceSlider
        x: 200
        y: 29
        stepSize: 1
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
            x: 141
            y: 0
            text: priceSlider.value
            horizontalAlignment: Text.AlignRight
        }
    }

    Slider {
        id: mileageSlider
        x: 200
        y: 70
        stepSize: 1
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
            x: 141
            y: -3
            text: mileageSlider.value
            horizontalAlignment: Text.AlignRight
        }

        Connections  {
            target: mileageSlider
            onMoved: mileage.text = mileageSlider.value
        }



    }

    ComboBox {
        id: comboBox
        x: 162
        y: 107
        width: 276
        height: 43
        model: ["Car Brand", "Audi", "BMW", "Hyundai", "Mercedes", "Skoda","Toyota",  "Vauxhall", "Volkswagen" ]

        onCurrentTextChanged: backend.brand = comboBox.currentText
    }

    ColumnLayout {
        x: 238
        y: 156
        spacing: 2


        RadioButton {
            id: avl
            text: qsTr("AVL Tree")
            onClicked: backend.treeType = "avl"
        }

        RadioButton {
            id: bst
            text: qsTr("BST")
            onClicked: backend.treeType = "bst"
        }
    }

    Button {
        id: searchButton
        x: 265
        y: 272
        text: qsTr("Search!")

        onClicked: backend.searchTree

        Connections {
            target: searchButton
            onClicked: stackView.push("Results.ui.qml")
        }
    }



}
