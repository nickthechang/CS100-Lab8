#ifndef POW_HPP
#define POW_HPP

#include <math.h>
#include "base.hpp"
#include "op.hpp"
#include <iomanip>
#include <sstream>
using namespace std;
#include "iterator.hpp"
#include "visitor.hpp"
#include <string>


class Pow : public Base {
    private:
        Base* left;
        Base* right;

        string lstring;
		    string rstring;
		    double ldouble;
		    double rdouble;
    public:
        Pow(Base* val1, Base* val2) : Base() {
            left = val1;
            right = val2;
        }
        virtual double evaluate() {
            ldouble = left -> evaluate();
			rdouble = right -> evaluate();
			double result = 0;
			if (rdouble == 0) {
				return 1.0;
			}
			result = ldouble;
			for (int i = 0; i < rdouble - 1; i++) {
				result = result * ldouble;
			}

            return result;
        }
        virtual string stringify() { 
            lstring = left -> stringify();
			      rstring = right -> stringify();
            return lstring + " ** " + rstring;
        }

        
        Base* get_left() {
          return left;
        }
		    Base* get_right() {
          return right;
        }
		    Iterator* create_iterator() {
		      Iterator* it = new BinaryIterator(this);
		      return it;
		    }
		    void accept(CountVisitor* vis) {
		      vis->visit_pow();
        }

};

#endif 
