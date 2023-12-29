//  inisialisasi pin yang digunakan
const int relay = 13;
const int redLamp = 12;
const int yellowLamp = 11;
const int greenLamp = 10;
const int moistureCencor = A0;

void setup()
{
  // Setup pinmode
  pinMode(relay, OUTPUT);
  pinMode(redLamp, OUTPUT);
  pinMode(greenLamp, OUTPUT);
  pinMode(yellowLamp, OUTPUT);
  pinMode(moistureCencor, INPUT);
  Serial.begin(9600);
}

void loop()
{

  //  mengaktifkan sensor tanah
  digitalWrite(moistureCencor, HIGH);
  // membaca sensor tanah
  int nilai = analogRead(moistureCencor);

  // menntukan aksi sesuai nilai
  if (nilai < 500)
  {
    digitalWrite(relay, LOW);
    digitalWrite(redLamp, LOW);
    digitalWrite(yellowLamp, LOW);
    digitalWrite(greenLamp, HIGH);
    Serial.println("Kelembapan tanah : " + nilai + " || Status : Kondisi tanah bagus");
  }
  else if (nilai < 800)
  {
    digitalWrite(relay, HIGH);
    digitalWrite(redLamp, LOW);
    digitalWrite(yellowLamp, HIGH);
    digitalWrite(greenLamp, LOW);
    Serial.println("Kelembapan tanah : " + nilai + " || Status : Kondisi tanah cukup bagus");
  }
  else
  {
    digitalWrite(relay, HIGH);
    digitalWrite(redLamp, HIGH);
    digitalWrite(yellowLamp, LOW);
    digitalWrite(greenLamp, LOW);
    Serial.println("Kelembapan tanah : " + nilai + " || Status : Kondisi tanah kekurangan air");
  }

  // mengatur delay aksi
  delay(1000);
}