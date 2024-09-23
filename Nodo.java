import java.util.ArrayList;

public class Nodo {
    
    private int id;
    private ArrayList<Nodo> adyacentes = new ArrayList<>();
    private ArrayList<Integer> distancias = new ArrayList<>();
    private ArrayList<Via> ubicacion = new ArrayList<>();

    public Nodo(int id){
        this.id = id;
    }

    // Getter para adyacentes
    public ArrayList<Nodo> getAdyacentes() {
        return adyacentes;
    }

    // Setter para adyacentes
    public void setAdyacentes(ArrayList<Nodo> adyacentes) {
        this.adyacentes = adyacentes;
    }

    // Getter para vias
    public ArrayList<Via> getUbicacion() {
        return ubicacion;
    }

    // Setter para la ubicacion
    public void setUbicacion(ArrayList<Via> ubicacion) {
        this.ubicacion = ubicacion;
    }

    public ArrayList<Integer> getDistancias(){
        return this.distancias;
    }

    public void setDistancias(ArrayList<Integer> dist){
        this.distancias = dist;
    }

    public void setID(int id){
        this.id = id;
    }

    public int getId(){
        return this.id;
    }
}
