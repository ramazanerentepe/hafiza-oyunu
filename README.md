# Hafıza Oyunu

> **Görsel Programlama dersi – 1. Ödev** kapsamında geliştirilmiştir.

Qt (C++) ile yazılmış basit bir kart eşleştirme (hafıza) oyunu. Kartlar ters çevrili başlar; aynı resme sahip iki kartı bularak tüm çiftleri eşleştirmeye çalışırsınız.

| | |
|---|---|
| **Ders** | Görsel Programlama |
| **Ödev** | Ödev 1 |
| **Geliştirici** | Ramazan Eren Tepe |
| **Dil / Çatı** | C++17, Qt 6 Widgets |
| **Derleme** | CMake, Qt Creator (Qt 6.12.0, MinGW 64-bit) |

## Oyun Kuralları ve Özellikler

- Oyunda **10 kart (5 çift)** bulunur: bomba, baykuş, kedi, zürafa ve penguen.
- Kartlar her oyun başında **rastgele karıştırılır**.
- İlk karta tıklandığında **süre sayacı** başlar (`dd:ss` formatında).
- Aynı anda iki kart açılır:
  - Resimler aynıysa kartlar açık kalır.
  - Farklıysa **1 saniye** sonra tekrar kapanır ve **hatalı deneme sayacı** bir artar.
- Tüm çiftler bulunduğunda süre durur.

## Proje Yapısı

```
├── CMakeLists.txt     # CMake derleme yapılandırması
├── main.cpp           # Uygulamanın giriş noktası
├── mainwindow.h       # Ana pencere sınıf tanımı
├── mainwindow.cpp     # Oyun mantığı (karıştırma, eşleştirme, süre)
├── mainwindow.ui      # Qt Designer arayüz dosyası
├── resources.qrc      # Resimlerin uygulamaya gömülmesi
└── images/            # Kart görselleri (arka yüz + 5 hayvan/nesne)
```

## Derleme ve Çalıştırma

### Depoyu klonlama
```bash
git clone https://github.com/ramazanerentepe/hafiza-oyunu.git
cd hafiza-oyunu
```

### Qt Creator ile
1. [Qt 6](https://www.qt.io/download) ve Qt Creator'ı kurun.
2. Qt Creator'da **File → Open File or Project** ile `CMakeLists.txt` dosyasını açın.
3. Bir kit seçin (ör. *Desktop Qt 6.x MinGW 64-bit*) ve **Run** (Ctrl+R) ile çalıştırın.

### Komut satırı ile
```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH="<Qt kurulum yolu>/6.x/mingw_64"
cmake --build build
```

## Hazır Sürüm (Windows)

Qt kurmadan çalıştırmak için derlenmiş sürüm, deponun [**Releases**](https://github.com/ramazanerentepe/hafiza-oyunu/releases) bölümünden zip olarak indirilebilir. Zip'i açıp `HafizaOyunu.exe` dosyasını çalıştırmanız yeterlidir.

> [!WARNING]
> Uygulama dijital olarak imzalanmadığı için Windows SmartScreen ilk açılışta
> **"Windows bilgisayarınızı korudu"** uyarısı gösterebilir. Bu, imzasız uygulamalar
> için normaldir. Çalıştırmak için **Ek bilgi → Yine de çalıştır** seçeneğine tıklayın.

## Lisans

Bu proje [Apache License 2.0](LICENSE) ile lisanslanmıştır.
