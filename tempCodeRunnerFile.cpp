{
    const double base_purchased = 1000.0;
    const double monthly_rate = 0.015;   // 1.5% per month
    const double monthly_payment = 50.0;

    // Variables
    double balance = base_purchased;
    double totalinterest = 0.0;
    double totalpaid = 0.0;

    int month = 0;
    while(balance >0.0){
        month++;
        double payment;
        double interest=balance*monthly_rate;
        double needtopay=balance+interest;
        if(needtopay<=monthly_payment){
            payment=needtopay;
        }
        else{
            payment=monthly_payment;
        }
        double realpay=payment-interest;
        balance= base_purchased-realpay;
        totalpaid+=payment;
        totalinterest+=interest;

         cout << setw(8) << month
             << setw(12) << interest
             << setw(12) << realpay
             << setw(12) << balance
             << setw(16) << totalinterest
             << setw(12) << totalpaid
             << endl;

    }
cout << fixed << setprecision(2);
cout << right;
cout << setw(8) << "Month#"
     << setw(12) << "Interest"
     << setw(12) << "Principal"
     << setw(12) << "Balance"
     << setw(16) << "TotalInterest"
     << setw(12) << "TotalPaid"
     << endl;
cout << endl;
    cout << "Months to pay off: " << month << endl;
    cout << "Total interest paid: " << totalinterest << endl;
    cout << "Total amount paid: " << totalpaid << endl;
return 0;
}