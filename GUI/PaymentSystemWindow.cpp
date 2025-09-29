#include "PaymentSystemWindow.hpp"
//================================
// Constructor & Destructor
PaymentSystemWindow::PaymentSystemWindow(QWidget *parent)
    : QMainWindow(parent), nextPaymentID(1001)
{
    setWindowTitle("Payment System - Qt GUI");
    setMinimumSize(800, 600);
    resize(1000, 700);
    //================================
    // Initialize with a default invoice
    currentInvoice = std::make_shared<Invoice>(1001, "Default Customer");

    setupUI();
    updateInvoiceDisplay();
}

PaymentSystemWindow::~PaymentSystemWindow()
{
}

//================================
// Main Window Setup
void PaymentSystemWindow::setupUI()
{
    centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    tabWidget = new QTabWidget;
    mainLayout->addWidget(tabWidget);

    setupCardPaymentTab();
    setupChequePaymentTab();
    setupInvoiceTab();
}

//================================
// Card Payment Tab Setup
void PaymentSystemWindow::setupCardPaymentTab()
{
    cardTab = new QWidget;
    tabWidget->addTab(cardTab, "Card Payment");

    QVBoxLayout *layout = new QVBoxLayout(cardTab);

    //================================
    // Card Payment Form
    QGroupBox *cardGroupBox = new QGroupBox("Add Card Payment");
    QFormLayout *formLayout = new QFormLayout(cardGroupBox);

    cardPaymentIDEdit = new QLineEdit(QString::number(nextPaymentID));
    cardPaymentIDEdit->setReadOnly(true);
    formLayout->addRow("Payment ID:", cardPaymentIDEdit);

    cardAmountSpinBox = new QDoubleSpinBox;
    cardAmountSpinBox->setRange(0.01, 999999.99);
    cardAmountSpinBox->setDecimals(2);
    cardAmountSpinBox->setValue(100.00);
    cardAmountSpinBox->setPrefix("$");
    formLayout->addRow("Amount:", cardAmountSpinBox);

    //================================
    // Card Information Inputs
    cardNumberEdit = new QLineEdit;
    cardNumberEdit->setPlaceholderText("1234567890123456");
    cardNumberEdit->setMaxLength(16);
    formLayout->addRow("Card Number:", cardNumberEdit);

    cardHolderEdit = new QLineEdit;
    cardHolderEdit->setPlaceholderText("John Doe");
    formLayout->addRow("Card Holder:", cardHolderEdit);

    cardExpiryEdit = new QLineEdit;
    cardExpiryEdit->setPlaceholderText("MM/YY");
    cardExpiryEdit->setMaxLength(5);
    formLayout->addRow("Expiry Date:", cardExpiryEdit);

    cardCvvSpinBox = new QSpinBox;
    cardCvvSpinBox->setRange(100, 9999);
    cardCvvSpinBox->setValue(123);
    formLayout->addRow("CVV:", cardCvvSpinBox);

    //================================
    // Card Buttons
    QHBoxLayout *cardButtonLayout = new QHBoxLayout;
    addCardButton = new QPushButton("Add Card Payment");
    addCardButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-weight: bold; padding: 8px; }");
    clearCardButton = new QPushButton("Clear Form");
    clearCardButton->setStyleSheet("QPushButton { background-color: #f44336; color: white; font-weight: bold; padding: 8px; }");

    cardButtonLayout->addWidget(addCardButton);
    cardButtonLayout->addWidget(clearCardButton);
    cardButtonLayout->addStretch();

    formLayout->addRow(cardButtonLayout);

    layout->addWidget(cardGroupBox);
    layout->addStretch();

    //================================
    // Connect signals
    connect(addCardButton, &QPushButton::clicked, this, &PaymentSystemWindow::addCardPayment);
    connect(clearCardButton, &QPushButton::clicked, this, &PaymentSystemWindow::clearCardForm);
}

//================================
// Cheque Payment Tab Setup
void PaymentSystemWindow::setupChequePaymentTab()
{
    chequeTab = new QWidget;
    tabWidget->addTab(chequeTab, "Cheque Payment");

    QVBoxLayout *layout = new QVBoxLayout(chequeTab);

    //================================
    // Cheque Payment Form
    QGroupBox *chequeGroupBox = new QGroupBox("Add Cheque Payment");
    QFormLayout *formLayout = new QFormLayout(chequeGroupBox);

    chequePaymentIDEdit = new QLineEdit(QString::number(nextPaymentID));
    chequePaymentIDEdit->setReadOnly(true);
    formLayout->addRow("Payment ID:", chequePaymentIDEdit);

    chequeAmountSpinBox = new QDoubleSpinBox;
    chequeAmountSpinBox->setRange(0.01, 999999.99);
    chequeAmountSpinBox->setDecimals(2);
    chequeAmountSpinBox->setValue(100.00);
    chequeAmountSpinBox->setPrefix("$");
    formLayout->addRow("Amount:", chequeAmountSpinBox);

    chequeNumberSpinBox = new QSpinBox;
    chequeNumberSpinBox->setRange(1, 999999);
    chequeNumberSpinBox->setValue(123456);
    formLayout->addRow("Cheque Number:", chequeNumberSpinBox);

    bankNameEdit = new QLineEdit;
    bankNameEdit->setPlaceholderText("Bank of Example");
    formLayout->addRow("Bank Name:", bankNameEdit);

    accountHolderEdit = new QLineEdit;
    accountHolderEdit->setPlaceholderText("John Doe");
    formLayout->addRow("Account Holder:", accountHolderEdit);

    //================================
    // Cheque Buttons
    QHBoxLayout *chequeButtonLayout = new QHBoxLayout;
    addChequeButton = new QPushButton("Add Cheque Payment");
    addChequeButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-weight: bold; padding: 8px; }");
    clearChequeButton = new QPushButton("Clear Form");
    clearChequeButton->setStyleSheet("QPushButton { background-color: #f44336; color: white; font-weight: bold; padding: 8px; }");

    chequeButtonLayout->addWidget(addChequeButton);
    chequeButtonLayout->addWidget(clearChequeButton);
    chequeButtonLayout->addStretch();

    formLayout->addRow(chequeButtonLayout);

    layout->addWidget(chequeGroupBox);
    layout->addStretch();

    //================================
    // Connect signals
    connect(addChequeButton, &QPushButton::clicked, this, &PaymentSystemWindow::addChequePayment);
    connect(clearChequeButton, &QPushButton::clicked, this, &PaymentSystemWindow::clearChequeForm);
}

//================================
// Invoice Tab Setup
void PaymentSystemWindow::setupInvoiceTab()
{
    invoiceTab = new QWidget;
    tabWidget->addTab(invoiceTab, "Invoice");

    QVBoxLayout *layout = new QVBoxLayout(invoiceTab);

    //================================
    // Invoice Header Inputs
    QGroupBox *invoiceHeaderBox = new QGroupBox("Invoice Information");
    QFormLayout *headerLayout = new QFormLayout(invoiceHeaderBox);

    invoiceIDEdit = new QLineEdit("1001");
    customerNameEdit = new QLineEdit("Default Customer");
    newInvoiceButton = new QPushButton("Create New Invoice");
    newInvoiceButton->setStyleSheet("QPushButton { background-color: #2196F3; color: white; font-weight: bold; padding: 8px; }");

    headerLayout->addRow("Invoice ID:", invoiceIDEdit);
    headerLayout->addRow("Customer Name:", customerNameEdit);
    headerLayout->addRow(newInvoiceButton);

    layout->addWidget(invoiceHeaderBox);

    //================================
    // Split view for payments table and invoice display
    QSplitter *splitter = new QSplitter(Qt::Horizontal);

    //================================
    // Left side - Payments Table
    QWidget *leftWidget = new QWidget;
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);

    QLabel *paymentsLabel = new QLabel("Payments:");
    paymentsLabel->setFont(QFont("Arial", 12, QFont::Bold));
    leftLayout->addWidget(paymentsLabel);

    paymentsTable = new QTableWidget(0, 4);
    QStringList headers = {"ID", "Type", "Amount", "Details"};
    paymentsTable->setHorizontalHeaderLabels(headers);
    paymentsTable->horizontalHeader()->setStretchLastSection(true);
    paymentsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    paymentsTable->setAlternatingRowColors(true);
    leftLayout->addWidget(paymentsTable);

    totalAmountLabel = new QLabel("Total: $0.00");
    totalAmountLabel->setFont(QFont("Arial", 14, QFont::Bold));
    totalAmountLabel->setStyleSheet("QLabel { color: #4CAF50; padding: 8px; border: 2px solid #4CAF50; border-radius: 4px; }");
    leftLayout->addWidget(totalAmountLabel);

    splitter->addWidget(leftWidget);

    //================================
    // Right side - Invoice Display Area
    QWidget *rightWidget = new QWidget;
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);

    QLabel *invoiceLabel = new QLabel("Invoice Details:");
    invoiceLabel->setFont(QFont("Arial", 12, QFont::Bold));
    rightLayout->addWidget(invoiceLabel);

    invoiceDisplayArea = new QTextEdit;
    invoiceDisplayArea->setReadOnly(true);
    invoiceDisplayArea->setFont(QFont("Courier", 9));
    rightLayout->addWidget(invoiceDisplayArea);

    refreshButton = new QPushButton("Refresh Display");
    refreshButton->setStyleSheet("QPushButton { background-color: #FF9800; color: white; font-weight: bold; padding: 8px; }");
    rightLayout->addWidget(refreshButton);

    splitter->addWidget(rightWidget);
    splitter->setSizes({400, 400});

    layout->addWidget(splitter);

    //================================
    // Connect signals
    connect(newInvoiceButton, &QPushButton::clicked, this, &PaymentSystemWindow::newInvoice);
    connect(refreshButton, &QPushButton::clicked, this, &PaymentSystemWindow::refreshInvoiceDisplay);
    connect(paymentsTable, &QTableWidget::cellDoubleClicked, this, &PaymentSystemWindow::showPaymentDetails);
}
//================================
// Payment Operations
void PaymentSystemWindow::addCardPayment()
{
    if (cardNumberEdit->text().isEmpty() || cardHolderEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    int paymentID = cardPaymentIDEdit->text().toInt();
    double amount = cardAmountSpinBox->value();
    long long cardNumber = cardNumberEdit->text().toLongLong();
    QString cardHolder = cardHolderEdit->text();
    QString expiry = cardExpiryEdit->text();
    int cvv = cardCvvSpinBox->value();

    auto cardPayment = std::make_shared<CardMethod>(
        paymentID, amount, cardNumber, cardHolder.toStdString(), expiry.toStdString(), cvv);

    currentInvoice->addPayment(cardPayment);
    //================================
    // Update UI
    nextPaymentID++;
    cardPaymentIDEdit->setText(QString::number(nextPaymentID));
    chequePaymentIDEdit->setText(QString::number(nextPaymentID));

    updateInvoiceDisplay();
    clearCardForm();

    QMessageBox::information(this, "Success", "Card payment added successfully!");
    saveInvoiceToCSV();
}

void PaymentSystemWindow::addChequePayment()
{
    if (bankNameEdit->text().isEmpty() || accountHolderEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    int paymentID = chequePaymentIDEdit->text().toInt();
    double amount = chequeAmountSpinBox->value();
    int chequeNumber = chequeNumberSpinBox->value();
    QString bankName = bankNameEdit->text();
    QString accountHolder = accountHolderEdit->text();

    auto chequePayment = std::make_shared<ChequeMethod>(
        paymentID, amount, chequeNumber, bankName.toStdString(), accountHolder.toStdString());

    currentInvoice->addPayment(chequePayment);
    //================================
    // Update UI
    nextPaymentID++;
    cardPaymentIDEdit->setText(QString::number(nextPaymentID));
    chequePaymentIDEdit->setText(QString::number(nextPaymentID));

    updateInvoiceDisplay();
    clearChequeForm();

    QMessageBox::information(this, "Success", "Cheque payment added successfully!");
    saveInvoiceToCSV();
}

void PaymentSystemWindow::clearCardForm()
{
    cardAmountSpinBox->setValue(100.00);
    cardNumberEdit->clear();
    cardHolderEdit->clear();
    cardExpiryEdit->clear();
    cardCvvSpinBox->setValue(123);
}

void PaymentSystemWindow::clearChequeForm()
{
    chequeAmountSpinBox->setValue(100.00);
    chequeNumberSpinBox->setValue(123456);
    bankNameEdit->clear();
    accountHolderEdit->clear();
}
//================================
// Invoice Display Updates
void PaymentSystemWindow::updateInvoiceDisplay()
{
    updatePaymentTable();
    //================================
    // Update total amount
    totalAmountLabel->setText(QString("Total: $%1").arg(currentInvoice->getTotalAmount(), 0, 'f', 2));
    //================================
    // Update invoice display area
    QString invoiceText = QString("========== INVOICE ==========\n");
    invoiceText += QString("Invoice ID: %1\n").arg(currentInvoice->getInvoiceID());
    invoiceText += QString("Customer: %1\n").arg(QString::fromStdString(currentInvoice->getCustomerName()));
    invoiceText += QString("Total Amount: $%1\n").arg(currentInvoice->getTotalAmount(), 0, 'f', 2);
    invoiceText += QString("Number of Payments: %1\n\n").arg(currentInvoice->getListOfPayments().size());

    auto payments = currentInvoice->getListOfPayments();
    for (size_t i = 0; i < payments.size(); ++i)
    {
        invoiceText += QString("Payment #%1:\n").arg(i + 1);
        invoiceText += QString("  ID: %1\n").arg(payments[i]->getPaymentID());
        invoiceText += QString("  Type: %1\n").arg(QString::fromStdString(payments[i]->getPaymentType()));
        invoiceText += QString("  Amount: $%1\n").arg(payments[i]->getAmount(), 0, 'f', 2);
        invoiceText += "----------------------------\n";
    }

    invoiceText += "============================";
    invoiceDisplayArea->setPlainText(invoiceText);
}

void PaymentSystemWindow::updatePaymentTable()
{
    auto payments = currentInvoice->getListOfPayments();
    paymentsTable->setRowCount(payments.size());

    for (size_t i = 0; i < payments.size(); ++i)
    {
        paymentsTable->setItem(i, 0, new QTableWidgetItem(QString::number(payments[i]->getPaymentID())));
        paymentsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(payments[i]->getPaymentType())));
        paymentsTable->setItem(i, 2, new QTableWidgetItem(QString("$%1").arg(payments[i]->getAmount(), 0, 'f', 2)));

        QString details;
        if (payments[i]->getPaymentType() == "Card")
        {
            details = "Card Payment";
        }
        else
        {
            details = "Cheque Payment";
        }
        paymentsTable->setItem(i, 3, new QTableWidgetItem(details));
    }
}
//================================
// Invoice Operations
void PaymentSystemWindow::newInvoice()
{
    bool ok;
    int invoiceID = invoiceIDEdit->text().toInt(&ok);
    if (!ok || invoiceID <= 0)
    {
        QMessageBox::warning(this, "Input Error", "Please enter a valid Invoice ID.");
        return;
    }

    QString customerName = customerNameEdit->text();
    if (customerName.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a customer name.");
        return;
    }

    currentInvoice = std::make_shared<Invoice>(invoiceID, customerName.toStdString());
    updateInvoiceDisplay();

    QMessageBox::information(this, "Success", "New invoice created successfully!");
}

void PaymentSystemWindow::refreshInvoiceDisplay()
{
    updateInvoiceDisplay();
}

void PaymentSystemWindow::showPaymentDetails()
{
    int row = paymentsTable->currentRow();
    if (row >= 0 && row < currentInvoice->getListOfPayments().size())
    {
        auto payment = currentInvoice->getListOfPayments()[row];

        QString details = QString("Payment ID: %1\n").arg(payment->getPaymentID());
        details += QString("Type: %1\n").arg(QString::fromStdString(payment->getPaymentType()));
        details += QString("Amount: $%1\n").arg(payment->getAmount(), 0, 'f', 2);

        QMessageBox::information(this, "Payment Details", details);
    }
}
//================================
// temporary CSV storage
void PaymentSystemWindow::saveInvoiceToCSV()
{
    std::ofstream outFile(simulatedServerFile.toStdString(), std::ios::app);
    if (!outFile.is_open())
        return;

    auto payments = currentInvoice->getListOfPayments();
    for (const auto &payment : payments)
    {
        outFile << currentInvoice->getInvoiceID() << ","
                << currentInvoice->getCustomerName() << ","
                << payment->getPaymentID() << ","
                << payment->getPaymentType() << ","
                << payment->getAmount() << "\n";
    }
    outFile.close();
}

void PaymentSystemWindow::clearCSV()
{
    std::ofstream outFile(simulatedServerFile.toStdString(), std::ios::trunc);
    outFile.close();
}

void PaymentSystemWindow::closeEvent(QCloseEvent *event)
{
    clearCSV(); // delete all temporary data
    event->accept();
}