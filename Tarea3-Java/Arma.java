public class Arma extends Item{
    private Float mult_str;
    private Float mult_int;

    public Arma(float mult_str,float mult_int,char representacion,String nombre){
        super(representacion,nombre);
        this.mult_str=mult_str;
        this.mult_int=mult_int;
    }



    /*
     * Funcion que permite calcular el ataque que hara un personaje cuando tenga un arma en especifico
     *
     * @int str_arma: parametro de tipo entero que representa el stat de fuerza del arma
     * @int inte_arma: parametro de tipo entero que representa el stat de inteligencia del arma
     *
     * @return : retorna el aumento el ataque total que el personaje haar con el arma equipada
     * */
    public Float calcularAtaque(int str_arma, int inte_arma){
            return mult_str*str_arma + mult_int*inte_arma;

    }


    //getters y setters
    public Float getMult_int() {
        return mult_int;
    }

    public Float getMult_str() {
        return mult_str;
    }

    public void setMult_int(Float mult_int) {
        this.mult_int = mult_int;
    }

    public void setMult_str(Float mult_str) {
        this.mult_str = mult_str;
    }
}
