import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Smart Timer")



    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        TimerPage {
        }

        TasksPage{
        }
    }
        header: TabBar {
            id: tabBar
            currentIndex: swipeView.currentIndex

            TabButton {
                text: qsTr("Timer" + swipeView.currentIndex)
            }
            TabButton {
                text: qsTr("Tasks")
            }
        }

}
