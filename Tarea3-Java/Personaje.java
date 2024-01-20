
public class Personaje implements Visible{
    private Float hp;
    private Integer nivel;


    //constructor
    public Personaje(float hp, int nivel){
        this.hp=hp;
        this.nivel=nivel;
    }
    //getters y setters
    public float getHp() {
        return hp;
    }

    public void setHp(float hp) {
        this.hp = hp;
    }

    public int getNivel() {
        return nivel;
    }

    public void setNivel(Integer nivel) {
        this.nivel = nivel;
    }


    public char getRepresentacion() {
        return 'O';
    }





    /*
     * Funcion que disminuye la vida del personaje cuando hay combate
     *
     * @Float hp: es un objeto de tipo Float que representa el hp del personaje
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void recibirDanio(Float hp){
        this.hp -= hp;
    }


    /*
     * Funcion que permite calcular el ataque que hace el personaje, el cual se implementado tanto en jugador como en el
     * personaje que representa el enemigo
     *
     * @no recibe parametros
     *
     * @return : devuelve un numero tipo float, que representa la cantidad de ataque que realizara un personaje de acuerdo
     * a su nivel
     * */
    public float calcularAtaque(){
        return 3f*nivel;
    }



}
