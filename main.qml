import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import an.qml.TransObj 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("矩阵计算器")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }

        TransObj {
            id:transobj;
            onValueFromCpp:{
                console.log("value from cpp :" + val);
            }
        }

        btnCal.onClicked: {
            transobj.getValFromQml(textEdit.text);
        }
    }
}
