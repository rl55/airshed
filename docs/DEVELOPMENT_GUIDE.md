📚 AirShed Intelligence Platform - Development Guide

🎯 PROJECT OVERVIEW
the AirShed Intelligence Platform v2.0, a comprehensive IoT-based air quality monitoring system for Indian cities. This platform combines real-time sensor data, Google Airview+ street-level measurements, and ArcGIS spatial analytics to provide actionable air quality insights to citizens, government bodies, and healthcare organizations.
Core Objectives:

Deploy a network of 10,000+ air quality sensors across Indian cities
Provide real-time AQI monitoring with <5 second latency
Enable predictive analytics for 24-72 hour forecasting
Support 1 million concurrent users
Integrate street-level pollution data at 1-meter resolution


🏗️ ARCHITECTURE SPECIFICATIONS
Technology Stack:
yamlFrontend:
  - Next.js 14 (App Router, Server Components)
  - React Native (Mobile apps)
  - TypeScript
  - Tailwind CSS
  - Shadcn/ui components
  - ArcGIS JS SDK 4.28
  - Leaflet for maps

Backend:
  - FastAPI (Python 3.11)
  - WebSocket (Socket.io)
  - KrakenD API Gateway
  - Keycloak (Authentication)

Databases:
  - PostgreSQL 15 (Metadata)
  - TimescaleDB (Time-series)
  - MongoDB 7 (Documents)
  - Qdrant (Vector database)
  - Redis 7 (Cache)
  - MinIO (Object storage)

Messaging:
  - Apache Kafka (Event streaming)
  - Eclipse Mosquitto (MQTT for IoT)
  - RabbitMQ (Service messaging)

Processing:
  - Apache Flink 1.18 (Stream processing)
  - Apache Spark 3.5 (Batch processing)
  - DBT Core (Data transformation)
  - Apache Airflow 2.8 (Orchestration)

Search & Analytics:
  - Elasticsearch 8.11 (Search/Logs)
  - Kibana (Log visualization)
  - Apache Superset (BI)
  - Grafana (Metrics)

ML/AI:
  - TensorFlow 2.15
  - Qdrant (Vector embeddings)
  - Sentence Transformers

DevOps:
  - Docker & Docker Compose
  - Kubernetes (K8s)
  - GitHub Actions (CI/CD)
  - Terraform (IaC)

📁 PROJECT STRUCTURE
Create the following directory structure:
bash
airshed-platform/
├── docker-compose.yml          # Main orchestration file
├── docker-compose.dev.yml      # Development overrides
├── docker-compose.prod.yml     # Production config
├── .env.example                # Environment variables template
├── Makefile                    # Build automation
│
├── frontend/                   # Next.js 14 Application
│   ├── app/                   # App Router
│   │   ├── (public)/         # Public routes (SSG)
│   │   │   ├── page.tsx      # Landing page
│   │   │   └── layout.tsx
│   │   ├── dashboard/        # Protected routes
│   │   │   ├── page.tsx
│   │   │   ├── devices/
│   │   │   ├── analytics/
│   │   │   └── settings/
│   │   ├── api/              # API routes
│   │   │   ├── aqi/route.ts
│   │   │   ├── search/route.ts
│   │   │   └── webhook/route.ts
│   │   └── layout.tsx        # Root layout
│   ├── components/
│   │   ├── ui/              # Shadcn components
│   │   ├── maps/            # Map components
│   │   │   ├── AQIHeatmap.tsx
│   │   │   ├── ArcGISScene.tsx
│   │   │   └── GoogleAirview.tsx
│   │   └── charts/          # Data viz
│   ├── lib/
│   │   ├── api.ts          # API client
│   │   ├── ws.ts           # WebSocket client
│   │   └── utils.ts
│   ├── public/
│   ├── package.json
│   ├── next.config.js
│   ├── tailwind.config.ts
│   └── Dockerfile
│
├── backend/                    # FastAPI Application
│   ├── app/
│   │   ├── main.py           # Application entry
│   │   ├── config.py         # Configuration
│   │   ├── dependencies.py   # Dependency injection
│   │   ├── api/
│   │   │   ├── v2/
│   │   │   │   ├── endpoints/
│   │   │   │   │   ├── aqi.py
│   │   │   │   │   ├── devices.py
│   │   │   │   │   ├── analytics.py
│   │   │   │   │   └── search.py
│   │   │   └── websocket.py
│   │   ├── core/
│   │   │   ├── security.py
│   │   │   ├── database.py
│   │   │   └── cache.py
│   │   ├── models/           # Pydantic models
│   │   ├── schemas/          # API schemas
│   │   ├── services/         # Business logic
│   │   │   ├── aqi_service.py
│   │   │   ├── vector_search.py
│   │   │   ├── airview_integration.py
│   │   │   └── arcgis_service.py
│   │   ├── db/              # Database models
│   │   │   ├── postgresql.py
│   │   │   ├── timescale.py
│   │   │   └── mongodb.py
│   │   └── ml/              # ML models
│   │       ├── predictor.py
│   │       └── embeddings.py
│   ├── tests/
│   ├── requirements.txt
│   ├── Dockerfile
│   └── alembic/             # Database migrations
│
├── gateway/                    # KrakenD Configuration
│   ├── krakend.json
│   ├── settings/
│   └── plugins/
│
├── processing/                 # Data Processing
│   ├── flink/
│   │   ├── src/
│   │   │   └── main/
│   │   │       └── java/
│   │   │           └── StreamProcessor.java
│   │   └── pom.xml
│   ├── spark/
│   │   ├── jobs/
│   │   │   ├── daily_aggregation.py
│   │   │   └── ml_training.py
│   │   └── requirements.txt
│   ├── dbt/
│   │   ├── models/
│   │   │   ├── staging/
│   │   │   ├── intermediate/
│   │   │   └── marts/
│   │   ├── tests/
│   │   ├── dbt_project.yml
│   │   └── profiles.yml
│   └── airflow/
│       ├── dags/
│       │   ├── data_pipeline.py
│       │   └── ml_pipeline.py
│       └── plugins/
│
├── devices/                    # IoT Device Code
│   ├── firmware/
│   │   ├── airscout_mobile/
│   │   │   └── airscout_mobile.ino
│   │   └── airscout_fixed/
│   │       └── main.py
│   └── deployment-app/       # Field deployment app
│       ├── src/
│       └── package.json
│
├── infrastructure/            # Infrastructure as Code
│   ├── terraform/
│   │   ├── modules/
│   │   ├── environments/
│   │   └── main.tf
│   ├── kubernetes/
│   │   ├── namespaces/
│   │   ├── deployments/
│   │   ├── services/
│   │   └── configmaps/
│   └── ansible/
│       └── playbooks/
│
├── monitoring/                # Monitoring Configuration
│   ├── prometheus/
│   │   └── prometheus.yml
│   ├── grafana/
│   │   └── dashboards/
│   ├── elasticsearch/
│   │   └── index-templates/
│   └── alerts/
│       └── rules.yml
│
├── scripts/                   # Utility Scripts
│   ├── setup.sh              # Initial setup
│   ├── deploy.sh             # Deployment script
│   └── backup.sh             # Backup script
│
└── docs/                      # Documentation
    ├── API.md
    ├── DEPLOYMENT.md
    ├── ARCHITECTURE.md
    └── TROUBLESHOOTING.md

🚀 IMPLEMENTATION STEPS
Step 1: Environment Setup
Create .env file:
bash# Database Credentials
DB_USER=airshed
DB_PASSWORD=secure_password_here
DB_NAME=airshed
DB_HOST=postgres
DB_PORT=5432

# TimescaleDB
TS_USER=timescale
TS_PASSWORD=secure_password_here
TS_HOST=timescaledb
TS_PORT=5432

# MongoDB
MONGO_USER=admin
MONGO_PASSWORD=secure_password_here
MONGO_HOST=mongodb
MONGO_PORT=27017

# Redis
REDIS_PASSWORD=secure_password_here
REDIS_HOST=redis
REDIS_PORT=6379

# Kafka
KAFKA_BROKERS=kafka:9093

# RabbitMQ
RABBITMQ_USER=admin
RABBITMQ_PASSWORD=secure_password_here

# External APIs
GOOGLE_AIRVIEW_API_KEY=your_key_here
ARCGIS_API_KEY=your_key_here
GOOGLE_MAPS_KEY=your_key_here

# Authentication
JWT_SECRET=your_jwt_secret_here
KEYCLOAK_ADMIN_PASSWORD=admin_password_here

# Monitoring
GRAFANA_PASSWORD=admin_password_here
ELASTIC_PASSWORD=elastic_password_here
Step 2: Backend Implementation (FastAPI)
backend/app/main.py:
pythonfrom fastapi import FastAPI, WebSocket
from fastapi.middleware.cors import CORSMiddleware
from contextlib import asynccontextmanager
import uvicorn

from app.api.v2 import api_router
from app.core.config import settings
from app.core.database import init_databases
from app.services.vector_search import VectorSearchService
from app.services.airview_integration import AirviewService
from app.services.websocket_manager import WSManager

@asynccontextmanager
async def lifespan(app: FastAPI):
    # Startup
    await init_databases()
    await VectorSearchService.initialize()
    await AirviewService.start_sync()
    yield
    # Shutdown
    await VectorSearchService.close()
    await AirviewService.stop_sync()

app = FastAPI(
    title="AirShed API",
    version="2.0.0",
    lifespan=lifespan
)

# CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=settings.CORS_ORIGINS,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Include routers
app.include_router(api_router, prefix="/api/v2")

# WebSocket endpoint
@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await WSManager.connect(websocket)
    try:
        while True:
            data = await websocket.receive_text()
            await WSManager.handle_message(websocket, data)
    except:
        WSManager.disconnect(websocket)

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)
Step 3: Frontend Implementation (Next.js 14)
frontend/app/page.tsx:
typescriptimport { Suspense } from 'react'
import dynamic from 'next/dynamic'
import { fetchAQIData, fetchAirviewData } from '@/lib/api'

const AQIMap = dynamic(() => import('@/components/maps/AQIHeatmap'), {
  ssr: false,
  loading: () => <MapSkeleton />
})

const ArcGISScene = dynamic(() => import('@/components/maps/ArcGISScene'), {
  ssr: false
})

export default async function HomePage() {
  // Server-side data fetching
  const [aqiData, airviewData] = await Promise.all([
    fetchAQIData(),
    fetchAirviewData()
  ])

  return (
    <main className="min-h-screen">
      <HeroSection />
      
      <section className="container mx-auto px-4 py-8">
        <h2 className="text-3xl font-bold mb-6">Real-time Air Quality</h2>
        
        <div className="grid lg:grid-cols-2 gap-6">
          <Suspense fallback={<MapSkeleton />}>
            <AQIMap initialData={aqiData} />
          </Suspense>
          
          <Suspense fallback={<div>Loading 3D view...</div>}>
            <ArcGISScene data={airviewData} />
          </Suspense>
        </div>
      </section>
      
      <VectorSearchSection />
      <HealthAdvisory aqiLevel={aqiData.current} />
    </main>
  )
}
Step 4: Vector Search Implementation
backend/app/services/vector_search.py:
pythonfrom qdrant_client import QdrantClient
from qdrant_client.models import Distance, VectorParams, PointStruct
from sentence_transformers import SentenceTransformer
import numpy as np

class VectorSearchService:
    client: QdrantClient = None
    encoder: SentenceTransformer = None
    
    @classmethod
    async def initialize(cls):
        cls.client = QdrantClient(host="qdrant", port=6333)
        cls.encoder = SentenceTransformer('all-MiniLM-L6-v2')
        
        # Create collections
        await cls.create_collections()
    
    @classmethod
    async def create_collections(cls):
        collections = {
            "pollution_patterns": VectorParams(size=384, distance=Distance.COSINE),
            "locations": VectorParams(size=768, distance=Distance.EUCLID),
            "documents": VectorParams(size=384, distance=Distance.DOT)
        }
        
        for name, params in collections.items():
            cls.client.create_collection(
                collection_name=name,
                vectors_config=params
            )
    
    @classmethod
    async def search_similar_patterns(cls, query: str, limit: int = 10):
        embedding = cls.encoder.encode(query)
        
        results = cls.client.search(
            collection_name="pollution_patterns",
            query_vector=embedding.tolist(),
            limit=limit
        )
        
        return [
            {
                "score": hit.score,
                "data": hit.payload,
                "id": hit.id
            }
            for hit in results
        ]
Step 5: Data Processing Pipeline
processing/flink/src/main/java/StreamProcessor.java:
javapackage com.airshed.processing;

import org.apache.flink.streaming.api.environment.StreamExecutionEnvironment;
import org.apache.flink.streaming.api.datastream.DataStream;
import org.apache.flink.streaming.connectors.kafka.FlinkKafkaConsumer;
import org.apache.flink.streaming.connectors.kafka.FlinkKafkaProducer;

public class StreamProcessor {
    public static void main(String[] args) throws Exception {
        StreamExecutionEnvironment env = 
            StreamExecutionEnvironment.getExecutionEnvironment();
        
        // Enable checkpointing
        env.enableCheckpointing(10000);
        
        // Kafka source
        FlinkKafkaConsumer<String> consumer = new FlinkKafkaConsumer<>(
            "sensor-data",
            new SimpleStringSchema(),
            kafkaProperties()
        );
        
        DataStream<String> stream = env.addSource(consumer);
        
        // Process stream
        DataStream<AQIReading> processed = stream
            .map(new ParseSensorData())
            .filter(new ValidateReading())
            .map(new CalculateAQI())
            .keyBy(reading -> reading.getDeviceId())
            .window(TumblingEventTimeWindows.of(Time.minutes(5)))
            .aggregate(new AQIAggregator());
        
        // Sink to TimescaleDB
        processed.addSink(new TimescaleDBSink());
        
        // Send alerts to RabbitMQ
        processed
            .filter(reading -> reading.getAqi() > 200)
            .addSink(new RabbitMQAlertSink());
        
        env.execute("AirShed Stream Processing");
    }
}

🔧 DEVELOPMENT COMMANDS
Quick Start:
bash# Clone and setup
git clone <repository>
cd airshed-platform
cp .env.example .env
# Edit .env with your credentials

# Start development environment
make dev-up

# Run database migrations
make db-migrate

# Seed initial data
make db-seed

# Start watching logs
make logs
Makefile:
makefile.PHONY: help dev-up dev-down prod-up prod-down test clean

help:
	@echo "AirShed Platform Commands:"
	@echo "  make dev-up     - Start development environment"
	@echo "  make dev-down   - Stop development environment"
	@echo "  make prod-up    - Start production environment"
	@echo "  make test       - Run all tests"
	@echo "  make clean      - Clean all containers and volumes"

dev-up:
	docker-compose -f docker-compose.yml -f docker-compose.dev.yml up -d
	@echo "Development environment started!"
	@echo "Frontend: http://localhost:3000"
	@echo "Backend: http://localhost:8000"
	@echo "Grafana: http://localhost:3001"
	@echo "Kibana: http://localhost:5601"

dev-down:
	docker-compose -f docker-compose.yml -f docker-compose.dev.yml down

prod-up:
	docker-compose -f docker-compose.yml -f docker-compose.prod.yml up -d

prod-down:
	docker-compose -f docker-compose.yml -f docker-compose.prod.yml down

test:
	docker-compose run --rm backend pytest
	docker-compose run --rm frontend npm test

db-migrate:
	docker-compose exec backend alembic upgrade head
	docker-compose exec backend python -m app.db.init_timescale

db-seed:
	docker-compose exec backend python -m app.db.seed

logs:
	docker-compose logs -f

clean:
	docker-compose down -v
	docker system prune -f

🧪 TESTING STRATEGY
Backend Tests:
python# backend/tests/test_api.py
import pytest
from httpx import AsyncClient
from app.main import app

@pytest.mark.asyncio
async def test_aqi_endpoint():
    async with AsyncClient(app=app, base_url="http://test") as client:
        response = await client.get("/api/v2/aqi/current?lat=28.6139&lng=77.2090")
        assert response.status_code == 200
        data = response.json()
        assert "aqi" in data
        assert 0 <= data["aqi"] <= 500

@pytest.mark.asyncio
async def test_vector_search():
    async with AsyncClient(app=app, base_url="http://test") as client:
        response = await client.post("/api/v2/search/semantic", json={
            "query": "high pollution morning traffic",
            "limit": 5
        })
        assert response.status_code == 200
        results = response.json()
        assert len(results) <= 5
Frontend Tests:
typescript// frontend/__tests__/AQIMap.test.tsx
import { render, screen, waitFor } from '@testing-library/react'
import AQIMap from '@/components/maps/AQIMap'

describe('AQIMap', () => {
  it('renders map with AQI data', async () => {
    const mockData = {
      sensors: [
        { id: '1', lat: 28.6139, lng: 77.2090, aqi: 156 }
      ]
    }
    
    render(<AQIMap initialData={mockData} />)
    
    await waitFor(() => {
      expect(screen.getByTestId('aqi-map')).toBeInTheDocument()
    })
  })
})

📊 MONITORING & OBSERVABILITY
Prometheus Metrics:
yaml# monitoring/prometheus/prometheus.yml
global:
  scrape_interval: 15s

scrape_configs:
  - job_name: 'airshed-backend'
    static_configs:
      - targets: ['backend:8000']
    
  - job_name: 'krakend'
    static_configs:
      - targets: ['krakend:9091']
    
  - job_name: 'node-exporter'
    static_configs:
      - targets: ['node-exporter:9100']
Grafana Dashboard:
json{
  "dashboard": {
    "title": "AirShed Platform Metrics",
    "panels": [
      {
        "title": "API Request Rate",
        "targets": [
          {
            "expr": "rate(http_requests_total[5m])"
          }
        ]
      },
      {
        "title": "Sensor Data Ingestion",
        "targets": [
          {
            "expr": "rate(sensor_readings_total[1m])"
          }
        ]
      },
      {
        "title": "AQI Levels by City",
        "targets": [
          {
            "expr": "avg(current_aqi) by (city)"
          }
        ]
      }
    ]
  }
}

🚢 DEPLOYMENT
Docker Compose Production:
yaml# docker-compose.prod.yml
version: '3.9'

services:
  backend:
    image: airshed/backend:latest
    deploy:
      replicas: 3
      resources:
        limits:
          cpus: '2'
          memory: 4G
    environment:
      - ENV=production
    
  frontend:
    image: airshed/frontend:latest
    deploy:
      replicas: 2
      resources:
        limits:
          cpus: '1'
          memory: 2G
Kubernetes Deployment:
yaml# infrastructure/kubernetes/deployments/backend.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: airshed-backend
  namespace: airshed
spec:
  replicas: 3
  selector:
    matchLabels:
      app: backend
  template:
    metadata:
      labels:
        app: backend
    spec:
      containers:
      - name: backend
        image: airshed/backend:latest
        ports:
        - containerPort: 8000
        env:
        - name: DATABASE_URL
          valueFrom:
            secretKeyRef:
              name: db-secret
              key: url
        resources:
          requests:
            memory: "1Gi"
            cpu: "500m"
          limits:
            memory: "2Gi"
            cpu: "1000m"
        livenessProbe:
          httpGet:
            path: /health
            port: 8000
          initialDelaySeconds: 30
          periodSeconds: 10

📝 CRITICAL IMPLEMENTATION NOTES
1. Vector Database Indexing:

Index pollution patterns every 5 minutes
Use cosine similarity for pattern matching
Maintain maximum 1M vectors per collection
Implement vector pruning for old data

2. Google Airview+ Integration:

Rate limit: 1000 requests/hour
Cache responses for 30 minutes
Fallback to sensor data if API fails
Store historical data in MinIO

3. ArcGIS Optimization:

Use Web Workers for heavy computations
Implement tile caching for base maps
Limit 3D rendering to 1000 features
Use Level of Detail (LOD) for performance

4. Real-time Updates:

WebSocket connection pooling
Maximum 10K concurrent connections per server
Implement exponential backoff for reconnection
Use Redis Pub/Sub for scaling WebSockets

5. Data Pipeline:

Implement exactly-once semantics in Flink
Use Kafka transactions for consistency
Set retention: 7 days for raw, 30 days for aggregated
Implement dead letter queues in RabbitMQ


🔐 SECURITY CHECKLIST

 Enable TLS/SSL for all services
 Implement API rate limiting
 Set up RBAC with Keycloak
 Encrypt sensitive data at rest
 Implement input validation
 Set up WAF rules in KrakenD
 Enable audit logging
 Implement secret rotation
 Set up network policies in K8s
 Regular security scanning


🎯 SUCCESS METRICS
Monitor these KPIs:

API Response Time: p99 < 100ms
Data Ingestion Rate: >50K messages/sec
System Uptime: >99.9%
Search Latency: <50ms
Frontend Load Time: <1.5s
WebSocket Latency: <100ms
ML Prediction Accuracy: >85%
Data Completeness: >95%


🆘 TROUBLESHOOTING GUIDE
Common Issues:
1. High Memory Usage:
bash# Check memory usage
docker stats
# Increase memory limits in docker-compose
# Implement pagination in queries
2. Slow Queries:
sql-- Add indexes
CREATE INDEX idx_readings_time ON sensor_readings(timestamp DESC);
CREATE INDEX idx_location ON sensor_readings USING GIST(location);
3. WebSocket Disconnections:
javascript// Implement reconnection logic
const reconnectWebSocket = () => {
  setTimeout(() => {
    ws = new WebSocket(wsUrl);
    setupWebSocketHandlers();
  }, Math.min(1000 * Math.pow(2, retryCount), 30000));
};

