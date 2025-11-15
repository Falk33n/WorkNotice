// Local includes
#include "StyledMessageBox.h"

// 3rd party includes
#include <QPushButton>
#include <Windows.h>

StyledMessageBox::StyledMessageBox(const QString &title, const QString &text,
                                   const QString &buttonText, QWidget *parent)
    : QMessageBox(parent) {
    createWindow();
    addTextContent(title, text);
    addCustomButton(buttonText);
    waitForButtonPressed();
}

void StyledMessageBox::createWindow() {
    playAlertSound();
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    addCss();
    makeWindowStayOnTop();
}

void StyledMessageBox::makeWindowStayOnTop() {
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

void StyledMessageBox::waitForButtonPressed() { exec(); }

void StyledMessageBox::playAlertSound() { MessageBeep(MB_ICONEXCLAMATION); }

void StyledMessageBox::addCss() {
    setStyleSheet("QMessageBox {"
                  "   background-color: #2b2b2b;"
                  "   color: white;"
                  "   border: none;"
                  "}"

                  "QLabel {"
                  "   color: white;"
                  "   font-size: 16px;"
                  "   font-weight: bold;"
                  "}"

                  "QPushButton {"
                  "   background-color: #4a90e2;"
                  "   color: white;"
                  "   padding: 8px 16px;"
                  "   border-radius: 8px;"
                  "   font-weight: bold;"
                  "}"

                  "QPushButton:hover {"
                  "   background-color: #6aa8ff;"
                  "}");
}

void StyledMessageBox::addCustomButton(const QString &buttonText) {
    // Remove default buttons
    setStandardButtons(QMessageBox::NoButton);

    // Add custom button
    QPushButton *startButton = addButton(buttonText, QMessageBox::AcceptRole);
    startButton->setCursor(Qt::PointingHandCursor);
}

void StyledMessageBox::addTextContent(const QString &title, const QString &text) {
    setWindowTitle(title);
    setText(text);
    setIcon(QMessageBox::Information);
}