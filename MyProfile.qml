import QtQuick 2.5

Item {


    Connections {
            target: controller

            onSendToQml: {
                    //t.text = s
                      // someNumber = s // Устанавливаем счётчик в текстовый лейбл
            }

    }


    Text{
        text: controller.getCompleted();
    }
}
