TARGET=sample_color
TARGET2=slides
all: $(TARGET).pdf $(TARGET2).pdf

$(TARGET2).pdf: $(TARGET2).ps 
	ps2pdf  $(TARGET2).ps $(TARGET2).pdf

$(TARGET).pdf: $(TARGET).ps 
	ps2pdf  $(TARGET).ps $(TARGET).pdf

$(TARGET2).ps: $(TARGET2).dvi $(wildcard *.eps)
	dvips  $(TARGET2).dvi -o $(TARGET2).ps

$(TARGET).ps: $(TARGET).dvi $(wildcard *.eps)
	dvips  $(TARGET).dvi -o $(TARGET).ps

$(TARGET2).dvi: $(TARGET2).tex 
	latex $(TARGET2).tex 

$(TARGET).dvi: $(TARGET).tex 
	latex $(TARGET).tex 

clean: 
	rm -f *~ *bak $(TARGET2).{vrb,snm,out,nav,toc,aux,ps,log,lof,bbl,blg,dvi,pdf} $(TARGET).{vrb,snm,out,nav,toc,aux,ps,log,lof,bbl,blg,dvi,pdf} 

.PHONY: clean
