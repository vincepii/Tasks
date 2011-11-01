#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QtGui/QWidget>
#include "ui_TaskWidget.h"

class TaskWidget : public QWidget
{
    Q_OBJECT

    /** The id of this task */
    std::string id_;

    /** The content of this task */
    std::string content_;

public:
    TaskWidget(std::string id, std::string content, QWidget *parent = 0);
    ~TaskWidget();

    /**
     * Sets the content as the taskLineEdit text
     */
    void displayContent();

    /**
     * Disables the synch button when the synch process has completed correctly
     */
    void synchDone();

public slots:
    /**
     * This slot receives the Synch button click signal
     */
    void synchronizeTask();

    /**
     * This slot receives the Delete button click signal
     */
    void deleteTask();

    /**
     * This slot receives the LineEdit textEdit signal
     */
    void markContentChanged(const QString &text);

    /**
     * Slot for the LineEdit editingFinished signal
     */
    void contentEditFinished();

signals:

    /**
     * Emits synch button pressed signal
     */
    void synchTaskSignal(std::string id);

    /**
     * Emits delete button pressed signal
     */
    void deleteTaskSignal(std::string id);

private:
    Ui::TaskWidgetClass ui;
};

#endif // TASKWIDGET_H
