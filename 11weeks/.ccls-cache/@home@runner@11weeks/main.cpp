int height, weight;
double bmi;

// Input height and weight
cin >> height >> weight;

// Calculate BMI
bmi = weight / pow((height / 100.0), 2);

// Check if the person is obese
if (bmi >= 25) {
  cout << "YES" << endl;
} else {
  cout << "NO" << endl;
}