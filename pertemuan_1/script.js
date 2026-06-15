// Mencegah form kontak melakukan refresh halaman dan memberikan notifikasi
document.getElementById('contactForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Mencegah reload
    
    // Anda bisa mengganti ini dengan layanan seperti Formspree atau EmailJS ke depannya
    alert('Terima kasih! Pesan Anda telah dikirim. (Catatan: Ini adalah demo, hubungkan dengan backend/API form untuk fungsi nyata).');
    
    // Mengosongkan form kembali
    this.reset();
});