package models;

import java.io.*;
import java.sql.*;
import java.util.*;
import java.math.*;


public class MapAccountCustomer implements Cloneable, Serializable {

    private int map_id;
    private int account_id;
    private int customer_id;

    public MapAccountCustomer () {

    }

    public MapAccountCustomer (int map_idIn) {
    	this.map_id = map_idIn;
    }

    public int getMap_id() {
          return this.map_id;
    }
    public void setMap_id(int map_idIn) {
          this.map_id = map_idIn;
    }

    public int getAccount_id() {
          return this.account_id;
    }
    public void setAccount_id(int account_idIn) {
          this.account_id = account_idIn;
    }

    public int getCustomer_id() {
          return this.customer_id;
    }
    public void setCustomer_id(int customer_idIn) {
          this.customer_id = customer_idIn;
    }



    /** 
     * setAll allows to set all persistent variables in one method call.
     * This is useful, when all data is available and it is needed to 
     * set the initial state of this object. Note that this method will
     * directly modify instance variales, without going trough the 
     * individual set-methods.
     */

    public void setAll(int map_idIn,
          int account_idIn,
          int customer_idIn) {
          this.map_id = map_idIn;
          this.account_id = account_idIn;
          this.customer_id = customer_idIn;
    }


    /** 
     * hasEqualMapping-method will compare two MapAccountCustomer instances
     * and return true if they contain same values in all persistent instance 
     * variables. If hasEqualMapping returns true, it does not mean the objects
     * are the same instance. However it does mean that in that moment, they 
     * are mapped to the same row in database.
     */
    public boolean hasEqualMapping(MapAccountCustomer valueObject) {

          if (valueObject.getMap_id() != this.map_id) {
                    return(false);
          }
          if (valueObject.getAccount_id() != this.account_id) {
                    return(false);
          }
          if (valueObject.getCustomer_id() != this.customer_id) {
                    return(false);
          }

          return true;
    }



    /**
     * toString will return String object representing the state of this 
     * valueObject. This is useful during application development, and 
     * possibly when application is writing object states in textlog.
     */
    public String toString() {
        StringBuffer out = new StringBuffer(this.getDaogenVersion());
        out.append("\nclass MapAccountCustomer, mapping to table map_account_customer\n");
        out.append("Persistent attributes: \n"); 
        out.append("map_id = " + this.map_id + "\n"); 
        out.append("account_id = " + this.account_id + "\n"); 
        out.append("customer_id = " + this.customer_id + "\n"); 
        return out.toString();
    }


    /**
     * Clone will return identical deep copy of this valueObject.
     * Note, that this method is different than the clone() which
     * is defined in java.lang.Object. Here, the retuned cloned object
     * will also have all its attributes cloned.
     */
    public Object clone() {
        MapAccountCustomer cloned = new MapAccountCustomer();

        cloned.setMap_id(this.map_id); 
        cloned.setAccount_id(this.account_id); 
        cloned.setCustomer_id(this.customer_id); 
        return cloned;
    }



    /** 
     * getDaogenVersion will return information about
     * generator which created these sources.
     */
    public String getDaogenVersion() {
        return "DaoGen version 2.4.1";
    }

}

             