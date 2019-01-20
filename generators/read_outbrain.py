import os

## Simple Generator for reading file
# Reads in data from the outbrain kaggle comp
# https://www.kaggle.com/c/outbrain-click-prediction/data

data_folder = '../data/'
page_view_sample = 'page_views_sample.csv' # page views sample

def field_map(dictseq, name, func):
    for d in dictseq:
        d[name] = func(d[name])
        yield d

if __name__ == '__main__':

    # page view columns
    colnames = ('uuid', 'document_id', 'timestamp', 'platform', 
                'geo_location', 'traffic_source')

    page_view_samp = os.path.join(data_folder, page_view_sample)

    with open(page_view_samp, 'r') as pageviews:
        headerline = next(pageviews).split(',')
        tuples = (dict(zip(headerline, line.split(','))) for line in pageviews)
        tuples = field_map(tuples, "document_id", int)
        lowid = (i for i in tuples if i['document_id'] < 1000)

        for r in lowid:
            print(r['timestamp'])
    
    #print(headerline)