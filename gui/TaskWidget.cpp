#include "TaskWidget.h"

TaskWidget::TaskWidget(std::string id, std::string content, QWidget *parent)
: QWidget(parent)
{
    ui.setupUi(this);

    id_ = id;
    content_ = content;

    // make the connections
    connect(ui.synchToolButton, SIGNAL(clicked()), this, SLOT(synchronizeTask()));
    connect(ui.deleteToolButton, SIGNAL(clicked()), this, SLOT(deleteTask()));
    connect(ui.taskLineEdit, SIGNAL(textEdited(const QString&)), this, SLOT(markContentChanged(const QString&)));
    connect(ui.taskLineEdit, SIGNAL(editingFinished()), this, SLOT(contentEditFinished()));

}

void TaskWidget::displayContent()
{
    ui.taskLineEdit->setText(QString::fromStdString(content_));
}

void TaskWidget::synchDone()
{
    ui.synchToolButton->setEnabled(false);
}

TaskWidget::~TaskWidget()
{
}

////----    SLOTS    ----////

void TaskWidget::synchronizeTask()
{
    emit synchTaskSignal(id_);
}

void TaskWidget::deleteTask()
{
    emit deleteTaskSignal(id_);
}

void TaskWidget::markContentChanged(const QString &text)
{
    if (text.toStdString() != content_)
        ui.synchToolButton->setEnabled(true);
    else {
        ui.synchToolButton->setEnabled(false);
    }
}

void TaskWidget::contentEditFinished()
{
    std::string newText = (ui.taskLineEdit->text()).toStdString();
    if (newText == content_) {
        // Neutral editing
        ui.synchToolButton->setEnabled(false);
    }
    else {
        content_ = newText;
        ui.synchToolButton->setEnabled(true);
    }
}
