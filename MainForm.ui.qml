import QtQuick 2.6
import QtQuick.Controls 2.2
import an.qml.TransObj 1.0

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit
    property alias btnCal: btnCal


    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    TextEdit {
        id: textEdit
        width: 240
        height: 30
        font.pointSize: 14
        text: qsTr("")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Button {
        id: btnCal;
        text: "计算";
        anchors.right:parent.right;
        anchors.bottom: parent.bottom;
    }
}
