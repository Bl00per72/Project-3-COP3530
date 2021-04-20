import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: page
    width: 600
    height: 400

    title: qsTr("Results")

    Label {
        id: label
        color: "#2d3037"
        text: qsTr("You are on the results page.")
        anchors.centerIn: parent
    }
    states: [
        State {
            name: "no results"

            PropertyChanges {
                target: label
                color: "#2d3037"
                text: qsTr("No results found, please enter a new search")
            }
        }
    ]
}
