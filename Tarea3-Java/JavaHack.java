
import java.util.Scanner;

public class JavaHack {
    public static void main(String[] args) {
        String comando;
        Scanner scan =new Scanner(System.in);
        System.out.println("Inicio del juego...");
        System.out.print("Cual es tu nombre?: ");
        String nombre= scan.nextLine();
        System.out.println("Ingrese ancho: ");
        int ancho=scan.nextInt();
        System.out.println("Ingrese alto: ");
        int alto=scan.nextInt();
        int option;


        Mundo mundo_principal = new Mundo(1,ancho,alto);
        mundo_principal.crearjugador(nombre);
        mundo_principal.generarMapa();
        System.out.println("B");

        boolean seguir=true;
        while(seguir){
            comando=scan.nextLine();

            switch (comando) {
                case "salir":
                    seguir = false;
                    break;
                case "w":
                        mundo_principal.moverJugador(mundo_principal.getPos_jugador_x(), mundo_principal.getPos_jugador_y() - 1);
                        break;
                case "s":
                        mundo_principal.moverJugador(mundo_principal.getPos_jugador_x(), mundo_principal.getPos_jugador_y() + 1);
                        break;
                case "a":
                        mundo_principal.moverJugador(mundo_principal.getPos_jugador_x() - 1, mundo_principal.getPos_jugador_y());
                        break;
                case "d":
                        mundo_principal.moverJugador(mundo_principal.getPos_jugador_x() + 1, mundo_principal.getPos_jugador_y());
                        break;

                case "i":
                    mundo_principal.mostrar_inventario();
                    break;

                case "q":
                    mundo_principal.stats();
                    break;

                case "equipar":
                    System.out.println("¿ Que item deseas equiparte ?");
                    mundo_principal.ver_inventario_mini();
                    option = scan.nextInt();
                    scan.nextLine();
                    mundo_principal.equiparse(option);
                    break;



            }
            if (mundo_principal.getEnemigos()==0){
                mundo_principal.nuevoNivel();
            }
            if(mundo_principal.getFin()==0){
                break;
            }
            mundo_principal.mostrar();
        }
        scan.close();

    }
}
