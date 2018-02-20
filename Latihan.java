/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package latihan;

/**
 *
 * @author Ahmad_Aji_Naufal_Ali
 */
public class Latihan {

    /**
     * @param args the command line arguments
     */
    int hlm;
    String judul;
    float cek;
    
    Latihan (String newJudul, int newHlm, float newCek) {
        this.judul = newJudul;
        this.hlm = newHlm;
        this.cek = newCek;
    }
    
    public void printInfo () {
        System.out.println("Judul   : " + judul);
        System.out.println("Halaman : " + hlm);
        System.out.println("Berat   : " + cek);
    }
  
    public static void main(String[] args) {
        // TODO code application logic here
        Latihan today = new Latihan ("Belajar Git", 69, 12121/20);
//        for(int i = 0; i < 10; i++){
//            System.out.println("Helloooo hoh hohohoh oh !");
//        }
        today.printInfo();
    }
}
